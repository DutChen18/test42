#include "test.h"

int
	test(void)
{
	int	ch;

	ch = -256;
	while (ch <= 256)
	{
		if (!test_ft_isalpha(ch))
			return (0);
		ch += 1;
	}
	return (1);
}
