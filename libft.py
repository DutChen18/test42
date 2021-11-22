def main(test, argv):
	ft_isalpha = test.Test("ft_isalpha")
	ft_isalpha.execs.append(test.Exec(["cc", "-shared", "libft/ft_isalpha/ft_isalpha.c", argv[0], "-o", "libft/ft_isalpha/ft_isalpha.so"]))
	ft_isalpha.cases["ascii"] = test.Exec(["./test", "libft/ft_isalpha/ft_isalpha.so", "main_ascii"])
