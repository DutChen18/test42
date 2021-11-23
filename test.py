#!/usr/bin/env python3
import asyncio
import sys
import os.path

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
	def __init__(self, cmd, stdin=None):
		self.cmd = cmd
		self.result = None
		self.stdin = stdin
	
	async def __await__(self):
		stdin = b""
		if self.stdin is not None:
			with open(self.stdin, "rb") as f:
				stdin = f.read()
		self.result = await pexec(self.cmd, stdin)

class Case(Exec):
	def __init__(self, name, cmd, stdin=None, opt=False, path=None):
		Exec.__init__(self, cmd, stdin)
		self.opt = opt
		self.ok = False
		self.name = name
		self.path = path or name

class Test:
	def __init__(self, name, path=None):
		self.execs = []
		self.cases = []
		self.name = name
		self.path = path or name
		tests.append(self)

	async def run(self):
		await asyncio.gather(*self.execs)
		for e in self.execs:
			if e.result[1] != b"":
				sys.stdout.write(e.result[1].decode())
		await asyncio.gather(*self.cases)
		for case in self.cases:
			stdout, stderr, returncode = case.result
			result = b""
			result += f"stdout {len(stdout)}\n".encode() + stdout
			result += f"stderr {len(stderr)}\n".encode() + stderr
			test_path = f"{project_name}/{self.path}/{case.path}.txt"
			diff_path = f"{project_name}/{self.name}/{case.name}.diff"
			if mode == "test":
				assert os.path.isfile(test_path)
				diff = await pexec(["diff", test_path, "-"], result)
				with open(diff_path, "wb") as f:
					f.write(diff[0])
				case.ok = diff[0] == b""
			elif mode == "record":
				with open(test_path, "wb") as f:
					f.write(result)

		if mode == "test":
			result_str = ""
			result_arr = ""
			for case in self.cases:
				if case.ok:
					result_str += " \033[1;32mOK\033[0m "
				elif case.opt:
					result_str += " \033[1;33mKO\033[0m "
					result_arr += f"\n\033[1;33mKO\033[0m \033[1;37m{case.name}\033[0m"
				else:
					result_str += " \033[1;31mKO\033[0m "
					result_arr += f"\n\033[1;31mKO\033[0m \033[1;37m{case.name}\033[0m"
			print(f"\033[1;37m{self.name:20}\033[0m{result_str}{result_arr}")
		else:
			print(self.name)

class CTest(Test):
	def __init__(self, name, args, path=None):
		Test.__init__(self, name, path=path)
		self.execs.append(Exec(["cc", *args, "-shared", "test.c", "-I", ".",
			f"{project_name}/{self.name}/{self.name}.c",
			"-o", f"{project_name}/{self.name}/{self.name}.so"]))

	def add(self, name, opt=False, mem=False):
		self.cases.append(Case(name, ["./test.out",
			f"{project_name}/{self.name}/{self.name}.so",
			f"main_{name}", "-1", "0"], opt=opt))
		if mem:
			self.cases.append(Case(name + "_mem", ["./test.out",
				f"{project_name}/{self.name}/{self.name}.so",
				f"main_{name}", "-1", "1"], opt=opt))

async def main(module, argv):
	global proc_sem
	proc_sem = asyncio.Semaphore(4)
	await pexec(["cc", "main.c", "-o", "test.out"])
	module.main(sys.modules[__name__], argv)
	await asyncio.gather(*[test.run() for test in tests])

if __name__ == "__main__":
	mode = sys.argv[1]
	project_name = sys.argv[2]
	module = __import__(project_name)
	asyncio.run(main(module, sys.argv[3:]))
