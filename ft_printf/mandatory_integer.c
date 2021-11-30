#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char *fmt, ...);

int
	main(int argc, char **argv)
{
	int	test;

	test = atoi(argv[1]);
	if (test == 0)
	{
		printf(" -> %d\n", ft_printf("%i", 0));
		fflush(stdout);
	}
	if (test == 1)
	{
		printf(" -> %d\n", ft_printf("%i", 2147483647));
		fflush(stdout);
	}
	if (test == 2)
	{
		printf(" -> %d\n", ft_printf("%i", -2147483648));
		fflush(stdout);
	}
	if (test == 3)
	{
		printf(" -> %d\n", ft_printf("%i", 1479280589));
		fflush(stdout);
	}
	if (test == 4)
	{
		printf(" -> %d\n", ft_printf("%i", -341142443));
		fflush(stdout);
	}
	if (test == 5)
	{
		printf(" -> %d\n", ft_printf("%i", 48424546));
		fflush(stdout);
	}
	if (test == 6)
	{
		printf(" -> %d\n", ft_printf("%i", -100515324));
		fflush(stdout);
	}
	if (test == 7)
	{
		printf(" -> %d\n", ft_printf("%i", 1752831507));
		fflush(stdout);
	}
	if (test == 8)
	{
		printf(" -> %d\n", ft_printf("%i", 20129910));
		fflush(stdout);
	}
	if (test == 9)
	{
		printf(" -> %d\n", ft_printf("%i", -936999309));
		fflush(stdout);
	}
	if (test == 10)
	{
		printf(" -> %d\n", ft_printf("%i", 1098670713));
		fflush(stdout);
	}
	if (test == 11)
	{
		printf(" -> %d\n", ft_printf("%i", 1727289611));
		fflush(stdout);
	}
	if (test == 12)
	{
		printf(" -> %d\n", ft_printf("%i", -815409959));
		fflush(stdout);
	}
	if (test == 13)
	{
		printf(" -> %d\n", ft_printf("%i", 987119867));
		fflush(stdout);
	}
	if (test == 14)
	{
		printf(" -> %d\n", ft_printf("%i", 790204970));
		fflush(stdout);
	}
	if (test == 15)
	{
		printf(" -> %d\n", ft_printf("%i", -1714975244));
		fflush(stdout);
	}
	if (test == 16)
	{
		printf(" -> %d\n", ft_printf("%i", -282729822));
		fflush(stdout);
	}
	if (test == 17)
	{
		printf(" -> %d\n", ft_printf("%i", 1773868988));
		fflush(stdout);
	}
	if (test == 18)
	{
		printf(" -> %d\n", ft_printf("%i", -98742266));
		fflush(stdout);
	}
	return (0);
}