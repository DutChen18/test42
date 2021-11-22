#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "test.h"

void	ft_striteri(const char *str, void (*f)(unsigned int, char*));

void
	test_toupper(unsigned int i, char *ch)
{
	*ch = toupper(*ch + i);
}

void
	test(const char *str)
{
	char	*str2;

	if (str != NULL)
		str2 = strdup(str);
	else if (str == NULL)
		str2 = (char *) str;
	ft_striteri(str2, test_toupper);
	printf("ft_striteri() -> %s\n", str2);
	if (str2 != NULL)
		libc_free(str2);
}

void
	test_random(int seed, int count)
{
	int		i;
	char	str[2049];

	str[2048] = '\0';
	while (0 < count)
	{
		i = 0;
		while (i < 2048)
		{
			seed = seed * 1103515245 + 12345;
			str[i] = (char)(unsigned char)(seed >> 16);
			i += 1;
		}
		test(str);
		count -= 1;
	}
}

void
	main_empty(void)
{
	test("");
}

void
	main_basic(void)
{
	test("Hello, World!");
	test("42");
}

void
	main_random(void)
{
	test_random(0, 256);
}

void
	main_null(void)
{
	test(NULL);
}
