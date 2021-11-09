import sys
import asyncio
import os.path
import os
import tempfile

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
		if test_mode == "record":
			asyncio.run(self._record())
		else:
			asyncio.run(self._run())

	async def _run(self):
		results = {}
		for test in self.tests:
			path = f"{self.name}/{test.name}.txt"
			result = await test.run(os.path.join(test_path, path))
			if result == "OK":
				results[test.name] = "\033[32mOK\033[0m"
			elif result == "KO":
				results[test.name] = "\033[31mKO\033[0m"
		results = "".join(f"{k:>16}={v}" for k, v in results.items())
		print(f"{self.name:16}{results}")

	async def _record(self):
		for test in self.tests:
			path = f"{self.name}/{test.name}.txt"
			await test.record(os.path.join(test_path, path))
		print(f"{self.name}")

class Test:
	def __init__(self, name, args, stdin):
		self.name = name
		self.args = args
		self.stdin = stdin

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
		result += f"stdout {len(stdout)}\n".encode()
		result += stdout
		result += f"stderr {len(stderr)}\n".encode()
		result += stderr
		result += f"return {returncode}\n".encode()
		return result

	async def record(self, path):
		with open(path, "wb") as f:
			f.write(await self.run_text())

	async def run(self, path):
		with open(path, "rb") as f:
			return "OK" if f.read() == (await self.run_text()) else "KO"

	async def setup(self):
		pass

class CTest(Test):
	def __init__(self, name, flags):
		Test.__init__(self, name, [], b"")
		self.flags = flags

	async def setup(self):
		out = os.path.join(tempfile.gettempdir(), "test42")
		cflags = self.flags + ["-o", out, "-I", test_path, "-I", proj_path]
		proc = await asyncio.create_subprocess_exec("cc", *cflags)
		await proc.wait()
		return out
