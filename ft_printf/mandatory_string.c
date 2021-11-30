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
		printf(" -> %d\n", ft_printf("%s", "Hello"));
		fflush(stdout);
	}
	if (test == 1)
	{
		printf(" -> %d\n", ft_printf("%s", "Hello World"));
		fflush(stdout);
	}
	if (test == 2)
	{
		printf(" -> %d\n", ft_printf("%s", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."));
		fflush(stdout);
	}
	if (test == 3)
	{
		printf(" -> %d\n", ft_printf("%s", ""));
		fflush(stdout);
	}
	if (test == 4)
	{
		printf(" -> %d\n", ft_printf("%s", " "));
		fflush(stdout);
	}
	if (test == 5)
	{
		printf(" -> %d\n", ft_printf("%s", "asdf"));
		fflush(stdout);
	}
	return (0);
}