#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);

void
	test(const char *str)
{
	unsigned long	len;

	len = (unsigned long) ft_strlen(str);
	printf("ft_strlen() -> %lu\n", len);
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
		test(str);
		count -= 1;
	}
}

void
	main_empty(void)
{
	test("");
}

void
	main_null(void)
{
	test(NULL);
}

void
	main_basic(void)
{
	test("Hello, World!");
	test("42");
	test("test");
}

void
	main_random(void)
{
	test_random(0, 256);
}
