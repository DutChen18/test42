#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "test.h"

char	*ft_strdup(const char *str);

void
	test(const char *str)
{
	char	*str2;

	str2 = ft_strdup(str);
	printf("ft_strdup() -> %s\n", str2);
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
	main_basic(void)
{
	test("Hello, World!");
	test("42");
}

void
	main_random(void)
{
	test_random(0, 256);
}

void
	main_null(void)
{
	test(NULL);
}
