#include <stdio.h>
#include <stdlib.h>

int	ft_isalnum(int ch);

void
	test(int ch)
{
	printf("ft_isalnum(%d) -> %d\n", ch, ft_isalnum(ch));
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

void
	main_ascii(void)
{
	test_range(0, 128);
}

void
	main_unsigned_char(void)
{
	test_range(0, 256);
}

void
	main_signed_char(void)
{
	test_range(-128, 128);
}

void
	main_random(void)
{
	test_random(0, 256);
}
