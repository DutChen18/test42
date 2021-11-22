import asyncio
import sys

proc_sem = asyncio.Semaphore(10)
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

class Test:
	def __init__(self, name):
		self.execs = []
		self.cases = {}
		self.name = name
		tests.append(self)

	async def run(self):
		await asyncio.gather(*self.execs)
		await asyncio.gather(*self.cases.values())
		for name, case in self.cases.items():
			stdout, stderr, returncode = case.result
			
			print(stdout, stderr, returncode)

async def main(module, argv):
	await pexec(["cc", "test.c", "-o", "test"])
	module.main(sys.modules[__name__], argv)
	await asyncio.gather(*[test.run() for test in tests])

if __name__ == "__main__":
	mode = sys.argv[1]
	module = __import__(sys.argv[2])
	asyncio.run(main(module, sys.argv[3:]))
