#include <stdio.h>
#include <stdlib.h>

char	*ft_strchr(const char *str, int ch);

void
	test(const char *str, int ch)
{
	char	*res;

	res = ft_strchr(str, ch);
	if (res == NULL)
		printf("ft_strchr() -> (null)\n");
	else
		printf("ft_strchr() -> %lu\n", (unsigned long)((char *) res - (char *) str));
}

void
	test_random(int seed, int count)
{
	int		i;
	char	str[2049];

	str[2048] = '\0';
	while (0 < count)
	{
		i = 0;
		while (i < 2048)
		{
			seed = seed * 1103515245 + 12345;
			str[i] = (char)(unsigned char)(seed >> 16);
			i += 1;
		}
		seed = seed * 1103515245 + 12345;
		test(str, seed >> 24);
		test(str, -(seed >> 24));
		test(str, seed >> 20);
		test(str, -(seed >> 20));
		count -= 1;
	}
}

void
	main_empty(void)
{
	test("", '\0');
	test("", 'a');
}

void
	main_null(void)
{
	test(NULL, 'a');
}

void
	main_basic(void)
{
	test("Hello, World!", ',');
	test("Hello, World!", 'J');
	test("Hello, World!", '\0');
}

void
	main_random(void)
{
	test_random(0, 256);
}
