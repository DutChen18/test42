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
		printf(" -> %d\n", ft_printf("%p", (void *) 0UL));
		fflush(stdout);
	}
	if (test == 1)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 7758176404715800194UL));
		fflush(stdout);
	}
	if (test == 2)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 15308084094301570617UL));
		fflush(stdout);
	}
	if (test == 3)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 8791662011684601223UL));
		fflush(stdout);
	}
	if (test == 4)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 9309829342914403545UL));
		fflush(stdout);
	}
	if (test == 5)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 5721212930748269353UL));
		fflush(stdout);
	}
	if (test == 6)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 12617276543794194196UL));
		fflush(stdout);
	}
	if (test == 7)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 10326739782786242647UL));
		fflush(stdout);
	}
	if (test == 8)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 8009056699280396679UL));
		fflush(stdout);
	}
	if (test == 9)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 4805234989534244506UL));
		fflush(stdout);
	}
	if (test == 10)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 259023674760142153UL));
		fflush(stdout);
	}
	if (test == 11)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 15496947691660677356UL));
		fflush(stdout);
	}
	if (test == 12)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 11534118754833929857UL));
		fflush(stdout);
	}
	if (test == 13)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 6145258598325499690UL));
		fflush(stdout);
	}
	if (test == 14)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 1161854816982873064UL));
		fflush(stdout);
	}
	if (test == 15)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 10468725429203222863UL));
		fflush(stdout);
	}
	if (test == 16)
	{
		printf(" -> %d\n", ft_printf("%p", (void *) 1682637359498011204UL));
		fflush(stdout);
	}
	return (0);
}