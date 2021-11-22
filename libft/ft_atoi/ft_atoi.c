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

void
	main_null(void)
{
	test(NULL);
}

void
	main_basic(void)
{
	test("-10");
	test("-9");
	test("-1");
	test("10");
	test("9");
	test("1");
	test("0");
}

void
	main_intmax(void)
{
	test("-2147483647");
	test("2147483647");
	test("2147483648");
	test("-2147483648");
}

void
	main_longmax(void)
{
	test("-9223372036854775807");
	test("9223372036854775807");
	test("9223372036854775808");
	test("-9223372036854775808");
}

void
	main_weird(void)
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
}

void
	main_random(void)
{
	test_random(0, 256);
}
