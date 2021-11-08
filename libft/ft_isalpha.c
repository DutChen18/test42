#include "test.h"
#include <ctype.h>
#include <locale.h>

int ft_isalpha(int ch);

int
	test_ft_isalpha(int ch)
{
	setlocale(LC_ALL, "C");
	return (ft_isalpha(ch) == isalpha(ch));
}
