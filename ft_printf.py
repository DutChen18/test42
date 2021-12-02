import os.path
import json
import random
import itertools

TEST_COUNT = 16

class Generator:
	def __init__(self, func):
		self.func = func
		self.code = []

	def __str__(self):
		result = []
		result.append(f"#include <stdio.h>")
		result.append(f"#include <stdlib.h>")
		result.append(f"")
		result.append(f"int {self.func}(const char *fmt, ...);")
		result.append(f"")
		result.append(f"int")
		result.append(f"\tmain(int argc, char **argv)")
		result.append(f"{{")
		result.append(f"\tint	test;")
		result.append(f"")
		result.append(f"\ttest = atoi(argv[1]);")
		result.append(f"\n".join(f"\t{code}" for code in self.code))
		result.append(f"\treturn (0);")
		result.append(f"}}")
		return "\n".join(result)

	def test(self, index, fmt, *args):
		args = "".join(f", {arg}" for arg in args)
		self.code.append(f"if (test == {index})")
		self.code.append(f"{{")
		self.code.append(f"\tprintf(\" -> %d\\n\", {self.func}({fmt}{args}));")
		self.code.append(f"\tfflush(stdout);")
		self.code.append(f"}}")

class PfChar:
	format = "c"
	name = "char"

	def values():
		yield (0,)
		random.seed(0)
		for i in range(TEST_COUNT):
			yield (random.randrange(2 ** 8),)
	
	def encode(value):
		return (str(value[0]),)

class PfString:
	format = "s"
	name = "string"

	def values():
		yield ("Hello",)
		yield ("Hello World",)
		yield ("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",)
		yield ("",)
		yield (" ",)
		yield ("asdf",)

	def encode(value):
		return (json.dumps(value[0]),)

class PfPointer:
	format = "p"
	name = "pointer"

	def values():
		yield (0,)
		random.seed(0)
		for i in range(TEST_COUNT):
			yield (random.randrange(2 ** 64),)

	def encode(value):
		return ("(void *) " + str(value[0]) + "UL",)

class PfDecimal:
	format = "d"
	name = "decimal"

	def values():
		yield (0,)
		yield (2**31-1,)
		yield (0-2**31,)
		random.seed(0)
		for i in range(TEST_COUNT):
			yield (random.randrange(0-2**31, 2**31),)

	def encode(value):
		return (str(value[0]),)

class PfInteger:
	format = "i"
	name = "integer"

	def values():
		yield (0,)
		yield (2**31-1,)
		yield (0-2**31,)
		random.seed(0)
		for i in range(TEST_COUNT):
			yield (random.randrange(0-2**31, 2**31),)

	def encode(value):
		return (str(value[0]),)

class PfUnsigned:
	format = "u"
	name = "unsigned"

	def values():
		yield (0,)
		yield (2**32-1,)
		random.seed(0)
		for i in range(TEST_COUNT):
			yield (random.randrange(2**32),)

	def encode(value):
		return (str(value[0]),)

class PfHexLower:
	format = "x"
	name = "hex_lower"

	def values():
		yield (0,)
		yield (2**32-1,)
		random.seed(0)
		for i in range(TEST_COUNT):
			yield (random.randrange(2**32),)

	def encode(value):
		return (str(value[0]),)

class PfHexUpper:
	format = "X"
	name = "hex_upper"

	def values():
		yield (0,)
		yield (2**32-1,)
		random.seed(0)
		for i in range(TEST_COUNT):
			yield (random.randrange(2**32),)

	def encode(value):
		return (str(value[0]),)

class PfEscape:
	format = "%"
	name = "escape"

	def values():
		yield ()

	def encode(value):
		return ()

def flags():
	flags = [["", "-"], ["", "0"], ["", "#"], ["", " "], ["", "+"]]
	preci = [("0",), ("1",), ("4",), ("16",), ("*",-16), ("*",-4), ("*",-1), ("*",0), ("*",1), ("*",4), ("*",16), ("",)]
	width = [("0",), ("1",), ("4",), ("16",), ("*",-16), ("*",-4), ("*",-1), ("*",0), ("*",1), ("*",4), ("*",16), ("",), None]
	random.seed(0)
	for f1, f2, f3, f4, f5, p, w in itertools.product(*flags, preci, width):
		fs = [f1, f2, f3, f4, f5]
		random.shuffle(fs)
		f1, f2, f3, f4, f5 = fs
		fmt = f"{f1}{f2}{f3}{f4}{f5}"
		if (fmt, p, w) == ("-", ("",), None):
			index = 0
		elif (fmt, p, w) == ("0", ("",), None):
			index = 1
		elif (fmt, p, w) == ("#", ("",), None):
			index = 2
		elif (fmt, p, w) == (" ", ("",), None):
			index = 3
		elif (fmt, p, w) == ("+", ("",), None):
			index = 4
		elif (fmt, w) == ("", None) and p != ("",):
			index = 5
		elif (fmt, p) == ("", ("",)) and w != None:
			index = 6
		else:
			index = 7
		arg = []
		fmt += p[0]
		arg += list(str(x) for x in p[1:])
		if w is not None:
			fmt += "." + w[0]
			arg += list(str(x) for x in w[1:])
		yield (index, fmt, *arg)

bonus_names = [
	"left",
	"zero",
	"alt",
	"space",
	"plus",
	"width",
	"precision",
	"mix",
]

conversions = [
	PfChar,
	PfString,
	PfPointer,
	PfDecimal,
	PfInteger,
	PfUnsigned,
	PfHexLower,
	PfHexUpper,
	PfEscape,
]

def gen_conv(gen, conv, use_flags=False):
	values = list((i, conv.format, *(conv.encode(x))) for i, x in enumerate(conv.values()))
	if use_flags:
		tmp = []
		for v in values:
			for f in flags():
				tmp.append((f[0], f[1] + v[1], *f[2:], *v[2:]))
		values = tmp
	for v in values:
		gen.test(v[0], json.dumps("%" + v[1]), *v[2:])

undefined = [
	"bonus_char_mix",
	"bonus_string_mix",
	"bonus_pointer_mix",
	"bonus_decimal_mix",
	"bonus_integer_mix",
	"bonus_unsigned_mix",
	"bonus_hex_lower_mix",
	"bonus_hex_upper_mix",
	"bonus_escape_mix",
	"bonus_char_precision",
	"bonus_char_zero",
	"bonus_char_alt",
	"bonus_char_space",
	"bonus_char_plus",
	"bonus_string_zero",
	"bonus_string_alt",
	"bonus_string_space",
	"bonus_string_plus",
	"bonus_pointer_plus",
	"bonus_unsigned_plus",
	"bonus_unsigned_space",
	"bonus_hex_lower_plus",
	"bonus_hex_lower_space",
	"bonus_hex_upper_plus",
	"bonus_hex_upper_space",
	"bonus_escape_precision",
	"bonus_escape_width",
	"bonus_escape_left",
	"bonus_escape_zero",
	"bonus_escape_alt",
	"bonus_escape_space",
	"bonus_escape_plus",
]

def main(test, argv):
	args = [argv[0]]
	if test.mode == "record":
		args.append("-Dft_printf=printf")
		args.append("-Wno-format")

	for conv in conversions:
		if test.mode == "record":
			gen = Generator("ft_printf")
			gen_conv(gen, conv, False)
			with open(f"ft_printf/mandatory_{conv.name}.c", "w") as f:
				f.write(str(gen))

		n = f"mandatory_{conv.name}"
		t = test.Test(n)
		t.execs.append(test.Exec(["cc", *args, f"ft_printf/{n}.c", "-o", f"ft_printf/{n}.out"]))
		t.execs.append(test.Exec(["mkdir", "-p", f"ft_printf/{n}"]))
		for i in range(len(list(conv.values()))):
			t.cases.append(test.Case(str(i), [f"ft_printf/{n}.out", str(i)]))

		if test.mode == "record":
			gen = Generator("ft_printf")
			gen_conv(gen, conv, True)
			with open(f"ft_printf/bonus_{conv.name}.c", "w") as f:
				f.write(str(gen))

		n = f"bonus_{conv.name}"
		t = test.Test(n)
		t.execs.append(test.Exec(["cc", *args, f"ft_printf/{n}.c", "-o", f"ft_printf/{n}.out"]))
		t.execs.append(test.Exec(["mkdir", "-p", f"ft_printf/{n}"]))
		for i in range(8):
			t.cases.append(test.Case(bonus_names[i], [f"ft_printf/{n}.out", str(i)], opt=(f"{n}_{bonus_names[i]}" in undefined)))
