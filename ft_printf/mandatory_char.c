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
		printf(" -> %d\n", ft_printf("%c", 0));
		fflush(stdout);
	}
	if (test == 1)
	{
		printf(" -> %d\n", ft_printf("%c", 197));
		fflush(stdout);
	}
	if (test == 2)
	{
		printf(" -> %d\n", ft_printf("%c", 215));
		fflush(stdout);
	}
	if (test == 3)
	{
		printf(" -> %d\n", ft_printf("%c", 20));
		fflush(stdout);
	}
	if (test == 4)
	{
		printf(" -> %d\n", ft_printf("%c", 132));
		fflush(stdout);
	}
	if (test == 5)
	{
		printf(" -> %d\n", ft_printf("%c", 248));
		fflush(stdout);
	}
	if (test == 6)
	{
		printf(" -> %d\n", ft_printf("%c", 207));
		fflush(stdout);
	}
	if (test == 7)
	{
		printf(" -> %d\n", ft_printf("%c", 155));
		fflush(stdout);
	}
	if (test == 8)
	{
		printf(" -> %d\n", ft_printf("%c", 244));
		fflush(stdout);
	}
	if (test == 9)
	{
		printf(" -> %d\n", ft_printf("%c", 183));
		fflush(stdout);
	}
	if (test == 10)
	{
		printf(" -> %d\n", ft_printf("%c", 111));
		fflush(stdout);
	}
	if (test == 11)
	{
		printf(" -> %d\n", ft_printf("%c", 71));
		fflush(stdout);
	}
	if (test == 12)
	{
		printf(" -> %d\n", ft_printf("%c", 144));
		fflush(stdout);
	}
	if (test == 13)
	{
		printf(" -> %d\n", ft_printf("%c", 71));
		fflush(stdout);
	}
	if (test == 14)
	{
		printf(" -> %d\n", ft_printf("%c", 48));
		fflush(stdout);
	}
	if (test == 15)
	{
		printf(" -> %d\n", ft_printf("%c", 128));
		fflush(stdout);
	}
	if (test == 16)
	{
		printf(" -> %d\n", ft_printf("%c", 75));
		fflush(stdout);
	}
	return (0);
}