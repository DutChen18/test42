#include <stdio.h>
#include <stdlib.h>

int	ft_isprint(int ch);

void
	test(int ch)
{
	printf("ft_isprint(%d) -> %d\n", ch, ft_isprint(ch));
}

void
	test_range(int start, int end)
{
	while (start < end)
	{
		test(start);
		start += 1;
	}
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

#ifdef TEST_ASCII
int
	main(void)
{
	test_range(0, 128);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_UNSIGNED_CHAR
int
	main(void)
{
	test_range(0, 256);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_SIGNED_CHAR
int
	main(void)
{
	test_range(-128, 128);
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
