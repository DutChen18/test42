#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "test.h"

char	*ft_substr(const char *str, unsigned int start, size_t len);

void
	test(const char *str, unsigned int start, size_t len)
{
	char	*str2;

	str2 = ft_substr(str, start, len);
	printf("ft_substr(%u, %lu) -> %s\n", start, (unsigned long) len, str2);
	printf("%lu unfreed mallocs\n", mallocs - frees);
	if (str2 != NULL)
	{
		if (do_test_mem) {
			printf("%lu malloc'd size\n", (unsigned long) malloc_size(str2));
		}
		free(str2);
	}
	printf("%lu unfreed mallocs\n", mallocs - frees);
}

void
	test_random(int seed, int count)
{
	int				i;
	char			str[2049];
	unsigned int	start;
	size_t			len;

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
		start = seed & 2047;
		seed = seed * 1103515245 + 12345;
		len = seed & 2047;
		test(str, start, len);
		count -= 1;
	}
}

void
	main_empty(void)
{
	test("", 0, 10);
	test("", 1, 10);
	test("", 5, 10);
	test("", 0, 0);
	test("", 1, 0);
	test("", 5, 0);
	test("", 0, 1);
	test("", 1, 1);
	test("", 5, 1);
}

void
	main_basic(void)
{
	test("Hello, World!", 0, 10);
	test("Hello, World!", 5, 10);
	test("Hello, World!", 13, 10);
	test("Hello, World!", 14, 10);
	test("Hello, World!", 15, 10);
	test("Hello, World!", 0, 0);
	test("Hello, World!", 5, 0);
	test("Hello, World!", 13, 0);
	test("Hello, World!", 14, 0);
	test("Hello, World!", 15, 0);
	test("Hello, World!", 0, 1);
	test("Hello, World!", 5, 1);
	test("Hello, World!", 13, 1);
	test("Hello, World!", 14, 1);
	test("Hello, World!", 15, 1);
	test("Hello, World!", 0, 8);
	test("Hello, World!", 5, 8);
	test("Hello, World!", 13, 8);
	test("Hello, World!", 14, 8);
	test("Hello, World!", 15, 8);
	test("Hello, World!", 0, 9);
	test("Hello, World!", 5, 9);
	test("Hello, World!", 13, 9);
	test("Hello, World!", 14, 9);
	test("Hello, World!", 15, 9);
}

void
	main_random(void)
{
	test_random(0, 256);
}

void
	main_null(void)
{
	test(NULL, 0, 0);
	test(NULL, 1, 0);
	test(NULL, 0, 1);
	test(NULL, 1, 1);
}
