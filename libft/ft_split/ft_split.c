#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "test.h"

char	**ft_split(const char *str, char ch);

void
	test(const char *str, char ch)
{
	char	**str2;
	char	**tmp;

	str2 = ft_split(str, ch);
	printf("ft_split(%c) -> (", ch);
	if (str2 != NULL)
	{
		tmp = str2;
		while (*tmp != NULL)
		{
			printf("%s, ", *tmp);
			tmp += 1;
		}
	}
	printf(")\n%lu unfreed mallocs\n", mallocs - frees);
	if (str2 != NULL)
	{
		if (do_test_mem) {
			printf("%lu malloc'd size\n", (unsigned long) malloc_size(str2));
		}
		tmp = str2;
		while (*tmp != NULL)
		{
			if (do_test_mem) {
				printf("%lu malloc'd size\n", (unsigned long) malloc_size(*tmp));
			}
			free(*tmp);
			tmp += 1;
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
		seed = seed * 1103515245 + 12345;
		test(str, (char)(unsigned char)(seed >> 16));
		count -= 1;
	}
}

void
	main_empty(void)
{
	test("", ' ');
}

void
	main_basic(void)
{
	test("Hello, World!", ' ');
	test("Hello, World!", ',');
	test("Hello, World!", 'a');
	test("   Hello,  World!   ", ' ');
}

void
	main_random(void)
{
	test_random(0, 256);
}

void
	main_null(void)
{
	test(NULL, ' ');
}
