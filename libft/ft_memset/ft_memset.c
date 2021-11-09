#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_memset(void *ptr, int ch, size_t size);

void
	test(void *ptr, int ch, size_t size, size_t writesize)
{
	void	*res;

	printf("ft_memset(ptr, %d, %lu) -> (", ch, (unsigned long) size);
	fflush(stdout);
	res = ft_memset(ptr, ch, size);
	write(STDOUT_FILENO, ptr, writesize);
	printf(", %lu)\n", (unsigned long)((char *) res - (char *) ptr));
	fflush(stdout);
}

void
	test_random(int seed, int count)
{
	size_t	size;
	char	str[256];

	test(str, '-', 256, 256);
	while (0 < count)
	{
		seed = seed * 1103515245 + 12345;
		size = seed & 255;
		seed = seed * 1103515245 + 12345;
		test(str, seed, size, 256);
		count -= 1;
	}
}

#ifdef TEST_EMPTY
int
	main(void)
{
	test((void *) "", '*', 0, 0);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL
int
	main(void)
{
	test(NULL, '*', 1, 0);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_RANDOM
int
	main(void)
{
	test_random(0, 256);
	return (EXIT_SUCCESS);
}
#endif
