#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "test.h"

char	*ft_itoa(int num);

void
	test(int num)
{
	char	*str;

	str = ft_itoa(num);
	printf("ft_itoa(%d) -> %s\n", num, str);
	printf("%lu unfreed mallocs\n", mallocs - frees);
	if (str != NULL)
	{
		if (do_test_mem) {
			printf("%lu malloc'd size\n", (unsigned long) malloc_size(str));
		}
		free(str);
	}
	printf("%lu unfreed mallocs\n", mallocs - frees);
}

void
	test_random(int seed, int count)
{
	while (0 < count)
	{
		seed = seed * 1103515245 + 12345;
		test(seed);
		count -= 1;
	}
}

void
	main_basic(void)
{
	test(-1);
	test(0);
	test(1);
}

void
	main_random(void)
{
	test_random(0, 256);
}

void
	main_intmax(void)
{
	test(0x7fffffff);
	test(-0x80000000);
}
