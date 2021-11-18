import sys
import asyncio
import os.path
import os
import tempfile
import secrets

whitelist = sys.argv[3:]
proj_path = sys.argv[2]
test_mode = sys.argv[1]
test_path = os.path.splitext(sys.argv[0])[0]

def join_proj(path):
	return os.path.join(proj_path, path)

def join_test(path):
	return os.path.join(test_path, path)

class Group:
	def __init__(self, name):
		self.name = name
		self.tests = []

	def add(self, test):
		self.tests.append(test)

	def start(self):
		asyncio.run(self.start_async())

	async def start_async(self):
		if test_mode == "record":
			await self.record()
		elif test_mode == "run":
			await self.run()

	async def run(self):
		if len(whitelist) > 0 and self.name not in whitelist:
			return
		results = await asyncio.gather(*[self.run_test(test) for test in self.tests])
		result_str = ""
		for i, result in enumerate(results):
			test = self.tests[i]
			if result == "OK":
				result_str += "  \033[1;32mOK\033[0m "
			elif result == "KO" and not test.options["opt"]:
				result_str += "  \033[1;31mKO\033[0m "
			elif result == "KO" and test.options["opt"]:
				result_str += "  \033[1;33mKO\033[0m "
		print(f"\033[1;37m{self.name:16}\033[0m{result_str}")
		for i, result in enumerate(results):
			test = self.tests[i]
			if result == "KO" and not test.options["opt"]:
				print(f"\033[1;31mKO\033[0m  \033[1;37m{self.name} {test.name}\033[0m")
			elif result == "KO" and test.options["opt"]:
				print(f"\033[1;33mKO\033[0m  \033[1;37m{self.name} {test.name}\033[0m")

	async def run_test(self, test):
		path = f"{self.name}/{test.name}.txt"
		result = await test.run(os.path.join(test_path, path))
		return result

	async def record(self):
		if len(whitelist) > 0 and self.name not in whitelist:
			return
		await asyncio.gather(*[self.record_test(test) for test in self.tests])
		print(f"{self.name}")

	async def record_test(self, test):
		path = f"{self.name}/{test.name}.txt"
		await test.record(os.path.join(test_path, path))

class Test:
	def __init__(self, name, args, stdin, opt):
		self.name = name
		self.args = args
		self.stdin = stdin
		self.options = {}
		self.options["opt"] = opt

	async def run_test(self):
		program = await self.setup()
		proc = await asyncio.create_subprocess_exec(program, *self.args,
			stdin=asyncio.subprocess.PIPE,
			stdout=asyncio.subprocess.PIPE,
			stderr=asyncio.subprocess.PIPE)
		stdout, stderr = await proc.communicate(self.stdin)
		return (stdout, stderr, proc.returncode)

	async def run_text(self):
		stdout, stderr, returncode = await self.run_test()
		result = b""
		if self.options.get("stdout", True):
			result += f"stdout {len(stdout)}\n".encode()
			result += stdout
		if self.options.get("stderr", True):
			result += f"stderr {len(stderr)}\n".encode()
			result += stderr
		if self.options.get("return", True):
			result += f"return {returncode}\n".encode()
		return result

	async def record(self, path):
		with open(path, "wb") as f:
			f.write(await self.run_text())

	async def run(self, path):
		with open(path, "rb") as f:
			expect = f.read()
		result = await self.run_text()
		proc = await asyncio.create_subprocess_exec("diff", path, "-",
			stdin=asyncio.subprocess.PIPE,
			stdout=asyncio.subprocess.PIPE)
		stdout, stderr = await proc.communicate(result)
		with open(os.path.splitext(path)[0] + ".diff", "wb") as f:
			f.write(stdout)
		return "OK" if expect == result else "KO"

	async def setup(self):
		pass

class CTest(Test):
	def __init__(self, name, flags, asan=True, libmem=True, opt=False):
		Test.__init__(self, name, [], b"", opt)
		self.options["asan"] = asan
		self.options["return"] = False
		self.options["libmem"] = libmem
		self.flags = flags

	async def setup(self):
		token = secrets.token_hex(16)
		out = os.path.join(tempfile.gettempdir(), "test42_" + token)
		cflags = self.flags + ["-o", out, "-I", test_path, "-I", proj_path]
		if self.options.get("asan", True):
			cflags += ["-g", "-fsanitize=address"]
		if self.options.get("libmem", True):
			base = os.path.dirname(__file__)
			libmem = os.path.join(base, "mem.c")
			cflags += ["-I", base, libmem]
		proc = await asyncio.create_subprocess_exec("cc", *cflags)
		await proc.wait()
		return out
