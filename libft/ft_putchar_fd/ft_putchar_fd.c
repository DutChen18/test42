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

void
	main_basic(void)
{
	test('\n');
	test('\0');
	test('h');
}

void
	main_random(void)
{
	test_random(0, 256);
}
