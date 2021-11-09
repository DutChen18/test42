#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

void
	test(const char *str)
{
	int	val;

	val = ft_atoi(str);
	printf("ft_atoi() -> %d\n", val);
}

void
	test_random(int seed, int count)
{
	int		i;
	char	str[257];

	str[256] = '\0';
	while (0 < count)
	{
		i = 0;
		while (i < 256)
		{
			seed = seed * 1103515245 + 12345;
			str[i] = (char)(unsigned char)(seed >> 16);
			i += 1;
		}
		test(str);
		count -= 1;
	}
}

#ifdef TEST_NULL
int
	main(void)
{
	test(NULL);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_BASIC
int
	main(void)
{
	test("-10");
	test("-9");
	test("-1");
	test("10");
	test("9");
	test("1");
	test("0");
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_INTMAX
int
	main(void)
{
	test("-2147483647");
	test("2147483647");
	test("2147483648");
	test("-2147483648");
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_LONGMAX
int
	main(void)
{
	test("-9223372036854775807");
	test("9223372036854775807");
	test("9223372036854775808");
	test("-9223372036854775808");
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_WEIRD
int
	main(void)
{
	test("");
	test("-");
	test("+");
	test("-++123");
	test("+-+123");
	test("");
	test("-");
	test("+");
	test("++123");
	test("--123");
	test(" ");
	test(" -");
	test(" +");
	test(" -++123");
	test(" +-+123");
	test(" ");
	test(" -");
	test(" +");
	test(" ++123");
	test(" --123");
	test("- ++123");
	test("+ -+123");
	test("+ +123");
	test("- -123");
	test(" - ++123");
	test(" + -+123");
	test(" + +123");
	test(" - -123");
	test("     -123");
	test("     +123");
	test("     123");
	test(" \t   -123");
	test(" \t   +123");
	test(" \t   123");
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_RANDOM
int
	main(void)
{
	test_random(0, 256);
	return (EXIT_SUCCESS);
}
#endif
