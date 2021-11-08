#!/usr/bin/env python3
import os
import os.path
import sys
import tempfile
import subprocess
import ctypes

class Test:
	def __init__(self, function, path):
		self.function = function
		self.path = path
		self.name = os.path.splitext(os.path.basename(path))[0]

	def run(self):
		cfg = {}
		cfg["path"] = self.function.project.proj_dir
		cflags = self.function.project.module.cflags(**cfg)
		obj = os.path.join(tempfile.gettempdir(), f"ft_{self.name}.so")
		cflags += ["-I", self.function.path, "-shared", "-o", obj]
		subprocess.run(["cc", self.path] + cflags)
		result = ctypes.cdll.LoadLibrary(obj).test()
		return "OK" if result != 0 else "KO"

class Function:
	def __init__(self, project, path):
		self.project = project
		self.path = path
		self.name = os.path.basename(path)

	def tests(self):
		for file in os.listdir(self.path):
			path = os.path.join(self.path, file)
			if os.path.isfile(path):
				yield Test(self, path)

class Project:
	def __init__(self, test_dir, proj_dir):
		self.test_dir = test_dir
		self.proj_dir = proj_dir
		self.name = os.path.basename(self.test_dir)
		self.module = __import__(os.path.basename(test_dir) + ".test").test

	def functions(self):
		for file in os.listdir(self.test_dir):
			path = os.path.join(self.test_dir, file)
			if os.path.isdir(path) and file != "__pycache__":
				yield Function(self, path)

def test_project(test_dir, proj_dir):
	project = Project(test_dir, proj_dir)
	print(f"### {project.name}")
	for function in project.functions():
		results = []
		for test in function.tests():
			results.append((test, test.run()))
		string = " ".join(test[1] for test in results)
		print(f"{function.name:20} {string}")
		for result in results:
			if result[1] != "OK":
				print(f"{result[0].name}: {result[1]}")

if __name__ == "__main__":
	test_dir = sys.argv[1]
	proj_dir = sys.argv[2]
	test_project(test_dir, proj_dir)
