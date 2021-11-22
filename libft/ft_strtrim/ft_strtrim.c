#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "test.h"

char	*ft_strtrim(const char *str1, const char *str2);

void
	test(const char *str1, const char *str2)
{
	char	*str3;

	str3 = ft_strtrim(str1, str2);
	printf("ft_strtrim() -> %s\n", str3);
	printf("%lu unfreed mallocs\n", mallocs - frees);
	if (str3 != NULL)
	{
		if (do_test_mem) {
			printf("%lu malloc'd size\n", (unsigned long) malloc_size(str3));
		}
		free(str3);
	}
	printf("%lu unfreed mallocs\n", mallocs - frees);
}

void
	test_random(int seed, int count)
{
	int		i;
	char	str[2049];
	size_t	str1;
	size_t	str2;

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
		str1 = seed & 2047;
		seed = seed * 1103515245 + 12345;
		str2 = seed & 2047;
		test(str + str1, str + str2);
		count -= 1;
	}
}

void
	main_empty(void)
{
	test("", "");
	test("", "a");
	test("a", "");
}

void
	main_basic(void)
{
	test("Hello, World!", "He!");
}

void
	main_random(void)
{
	test_random(0, 256);
}

void
	main_null(void)
{
	test(NULL, "");
	test("", NULL);
	test(NULL, NULL);
}
