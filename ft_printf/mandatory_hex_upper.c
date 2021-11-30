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
		printf(" -> %d\n", ft_printf("%X", 0));
		fflush(stdout);
	}
	if (test == 1)
	{
		printf(" -> %d\n", ft_printf("%X", 4294967295));
		fflush(stdout);
	}
	if (test == 2)
	{
		printf(" -> %d\n", ft_printf("%X", 3626764237));
		fflush(stdout);
	}
	if (test == 3)
	{
		printf(" -> %d\n", ft_printf("%X", 1806341205));
		fflush(stdout);
	}
	if (test == 4)
	{
		printf(" -> %d\n", ft_printf("%X", 2195908194));
		fflush(stdout);
	}
	if (test == 5)
	{
		printf(" -> %d\n", ft_printf("%X", 2046968324));
		fflush(stdout);
	}
	if (test == 6)
	{
		printf(" -> %d\n", ft_printf("%X", 3900315155));
		fflush(stdout);
	}
	if (test == 7)
	{
		printf(" -> %d\n", ft_printf("%X", 2167613558));
		fflush(stdout);
	}
	if (test == 8)
	{
		printf(" -> %d\n", ft_printf("%X", 1210484339));
		fflush(stdout);
	}
	if (test == 9)
	{
		printf(" -> %d\n", ft_printf("%X", 3246154361));
		fflush(stdout);
	}
	if (test == 10)
	{
		printf(" -> %d\n", ft_printf("%X", 3874773259));
		fflush(stdout);
	}
	if (test == 11)
	{
		printf(" -> %d\n", ft_printf("%X", 1332073689));
		fflush(stdout);
	}
	if (test == 12)
	{
		printf(" -> %d\n", ft_printf("%X", 3134603515));
		fflush(stdout);
	}
	if (test == 13)
	{
		printf(" -> %d\n", ft_printf("%X", 2937688618));
		fflush(stdout);
	}
	if (test == 14)
	{
		printf(" -> %d\n", ft_printf("%X", 432508404));
		fflush(stdout);
	}
	if (test == 15)
	{
		printf(" -> %d\n", ft_printf("%X", 1864753826));
		fflush(stdout);
	}
	if (test == 16)
	{
		printf(" -> %d\n", ft_printf("%X", 3921352636));
		fflush(stdout);
	}
	if (test == 17)
	{
		printf(" -> %d\n", ft_printf("%X", 2048741382));
		fflush(stdout);
	}
	return (0);
}