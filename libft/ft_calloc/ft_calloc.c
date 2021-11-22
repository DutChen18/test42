#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "test.h"

void	*ft_calloc(size_t size, size_t count);

void
	test(size_t size, size_t count)
{
	void	*ptr;

	ptr = ft_calloc(size, count);
	printf("ft_calloc(%lu, %lu) -> ", (unsigned long) size, (unsigned long) count);
	fflush(stdout);
	if (ptr != NULL)
		write(1, ptr, size * count);
	printf("\n");
	printf("%lu unfreed mallocs\n", mallocs - frees);
	if (ptr != NULL)
	{
		if (do_test_mem) {
			printf("%lu malloc'd size\n", (unsigned long) malloc_size(ptr));
		}
		free(ptr);
	}
	printf("%lu unfreed mallocs\n", mallocs - frees);
	fflush(stdout);
}

void
	main_zero(void)
{
	test(0, 0);
	test(0, 42);
	test(69, 0);
}

void
	main_basic(void)
{
	test(1, 42);
	test(69, 1);
	test(42, 69);
}

void
	main_null(void)
{
	test(1, 0x1000000000000);
	test(0x1000000000000, 1);
	test(0x1000000, 0x1000000);
}
