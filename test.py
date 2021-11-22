import asyncio
import sys

proc_sem = None
tests = []

async def pexec(cmd, stdin=b""):
	async with proc_sem:
		proc = await asyncio.create_subprocess_exec(*cmd,
			stdin=asyncio.subprocess.PIPE,
			stdout=asyncio.subprocess.PIPE,
			stderr=asyncio.subprocess.PIPE)
		stdout, stderr = await proc.communicate(stdin)
		return stdout, stderr, proc.returncode

class Exec:
	def __init__(self, cmd):
		self.cmd = cmd
		self.result = None
	
	async def __await__(self):
		self.result = await pexec(self.cmd)

class Case(Exec):
	def __init__(self, cmd, opt=False):
		Exec.__init__(self, cmd)
		self.opt = opt
		self.ok = False

class Test:
	def __init__(self, name):
		self.execs = []
		self.cases = {}
		self.name = name
		tests.append(self)

	async def run(self):
		await asyncio.gather(*self.execs)
		for e in self.execs:
			if e.result[1] != b"":
				sys.stdout.write(e.result[1].decode())
		await asyncio.gather(*self.cases.values())
		for name, case in self.cases.items():
			stdout, stderr, returncode = case.result
			result = b""
			result += f"stdout {len(stdout)}\n".encode() + stdout
			result += f"stderr {len(stderr)}\n".encode() + stderr
			path = f"{project_name}/{self.name}/{name}"
			if mode == "test":
				diff = await pexec(["diff", path + ".txt", "-"], result)
				with open(path + ".diff", "wb") as f:
					f.write(diff[0])
				case.ok = diff[0] == b""
			elif mode == "record":
				with open(path + ".txt", "wb") as f:
					f.write(result)

		result_str = ""
		result_arr = ""
		for name, case in self.cases.items():
			if case.ok:
				result_str += " \033[1;32mOK\033[0m "
			elif case.opt:
				result_str += " \033[1;33mKO\033[0m "
				result_arr += f"\n\033[1;33mKO\033[0m \033[1;37m{name}\033[0m"
			else:
				result_str += " \033[1;31mKO\033[0m "
				result_arr += f"\n\033[1;31mKO\033[0m \033[1;37m{name}\033[0m"
		print(f"\033[1;37m{self.name:16}\033[0m{result_str}{result_arr}")

class CTest(Test):
	def __init__(self, name, args):
		Test.__init__(self, name)
		self.execs.append(Exec(["cc", *args, "-shared", "test.c", "-I", ".",
			f"{project_name}/{self.name}/{self.name}.c",
			"-o", f"{project_name}/{self.name}/{self.name}.so"]))

	def add(self, name, opt=False, mem=False):
		self.cases[name] = Case(["./test",
			f"{project_name}/{self.name}/{self.name}.so",
			f"main_{name}", "-1", "0"], opt=opt)
		if mem:
			self.cases[name + "_mem"] = Case(["./test",
				f"{project_name}/{self.name}/{self.name}.so",
				f"main_{name}", "-1", "1"], opt=opt)

async def main(module, argv):
	global proc_sem
	proc_sem = asyncio.Semaphore(4)
	await pexec(["cc", "main.c", "-o", "test"])
	module.main(sys.modules[__name__], argv)
	await asyncio.gather(*[test.run() for test in tests])

if __name__ == "__main__":
	mode = sys.argv[1]
	project_name = sys.argv[2]
	module = __import__(project_name)
	asyncio.run(main(module, sys.argv[3:]))
