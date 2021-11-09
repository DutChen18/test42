#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_bzero(void *ptr, size_t size);

void
	test(void *ptr, size_t size, size_t writesize)
{
	printf("ft_bzero(%lu) -> ", (unsigned long) size);
	fflush(stdout);
	ft_bzero(ptr, size);
	write(STDOUT_FILENO, ptr, writesize);
	printf("\n");
	fflush(stdout);
}

void
	test_random(int seed, int count)
{
	int		i;
	size_t	size;
	char	str[256];

	while (0 < count)
	{
		seed = seed * 1103515245 + 12345;
		size = (seed >> 16) & 255;
		i = 0;
		while (i < 256)
		{
			seed = seed * 1103515245 + 12345;
			str[i] = (char)(unsigned char)(seed >> 16);
			i += 1;
		}
		test(str, size, 256);
		count -= 1;
	}
}

#ifdef TEST_EMPTY
int
	main(void)
{
	test((void *) "", 0, 0);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL
int
	main(void)
{
	test(NULL, 1, 0);
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
