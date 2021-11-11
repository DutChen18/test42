#include <stdio.h>
#include <stdlib.h>

void	ft_putchar_fd(char ch, int fd);

void
	test(char ch)
{
	ft_putchar_fd(ch, 1);
	ft_putchar_fd(ch, 2);
}

void
	test_random(int seed, int count)
{
	while (0 < count)
	{
		seed = seed * 1103515245 + 12345;
		test((char) seed);
		count -= 1;
	}
}

#ifdef TEST_BASIC
int
	main(void)
{
	test('\n');
	test('\0');
	test('h');
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
