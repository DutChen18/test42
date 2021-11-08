#include "test.h"

int
	test(void)
{
	int	ch;

	ch = 0;
	while (ch < 128)
	{
		if (!test_ft_isalpha(ch))
			return (0);
		ch += 1;
	}
	return (1);
}
