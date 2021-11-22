#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "test.h"

void	ft_putnbr_fd(int num, int fd);

void
	test(int num)
{
	ft_putnbr_fd(num, 1);
	ft_putnbr_fd(num, 2);
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
