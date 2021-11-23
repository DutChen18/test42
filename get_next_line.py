import os.path

def main(test, argv):
	args = ["-I", argv[0], "get_next_line/main.c"]
	mandatory = [
		os.path.join(argv[0], "get_next_line.c"),
		os.path.join(argv[0], "get_next_line_utils.c")]
	bonus = [
		os.path.join(argv[0], "get_next_line_bonus.c"),
		os.path.join(argv[0], "get_next_line_utils_bonus.c")]

	files = [
		"41_chars_nl", "43_chars_no_nl", "empty", "multiple_no_nl",
		"simple", "41_chars_no_nl", "alternating_nl", "hallo",
		"newline", "42_chars_nl", "alternating_no_nl", "lorumipsum",
		"notsoomanylines", "42_chars_no_nl", "big_line_nl", "manylines",
		"only_newlines", "43_chars_nl", "big_line_no_nl", "multiple_nl",
		"random"]
	sizes = [1, 2, 3, 4, 5, 42, 69, 100, 420, 1000, 1000000]
	if test.mode == "record":
		sizes = [42]

	for size in sizes:
		t = test.Test(f"mandatory_{size}", path="mandatory")
		t.execs.append(test.Exec(["cc", *args, *mandatory, "-o", f"get_next_line/mandatory_{size}.out", f"-DBUFFER_SIZE={size}"]))
		t.execs.append(test.Exec(["mkdir", "-p", f"get_next_line/mandatory_{size}"]))
		for file in files:
			t.cases.append(test.Case(file, [f"get_next_line/mandatory_{size}.out", f"get_next_line/{file}.txt"], path=file))
			if test.mode != "record":
				t.cases.append(test.Case(file + "_stdin", [f"get_next_line/mandatory_{size}.out"], stdin=f"get_next_line/{file}.txt", path=file))

	for size in sizes:
		t = test.Test(f"bonus_{size}", path="bonus")
		t.execs.append(test.Exec(["cc", *args, *bonus, "-o", f"get_next_line/bonus_{size}.out", f"-DBUFFER_SIZE={size}"]))
		t.execs.append(test.Exec(["mkdir", "-p", f"get_next_line/bonus_{size}"]))
		t.cases.append(test.Case("bonus", [f"get_next_line/mandatory_{size}.out", *[f"get_next_line/{file}.txt" for file in files]]))
