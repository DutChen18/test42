#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mem.h"

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
#ifdef TEST_MEM
		printf("%lu malloc'd size\n", (unsigned long) malloc_size(ptr));
#endif
		free(ptr);
	}
	printf("%lu unfreed mallocs\n", mallocs - frees);
	fflush(stdout);
}

#ifdef TEST_ZERO
int
	main(void)
{
	test(0, 0);
	test(0, 42);
	test(69, 0);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_BASIC
int
	main(void)
{
	test(1, 42);
	test(69, 1);
	test(42, 69);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL
int
	main(void)
{
	test(1, 0x1000000000000);
	test(0x1000000000000, 1);
	test(0x1000000, 0x1000000);
	return (EXIT_SUCCESS);
}
#endif
