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
		printf(" -> %d\n", ft_printf("%%"));
		fflush(stdout);
	}
	return (0);
}