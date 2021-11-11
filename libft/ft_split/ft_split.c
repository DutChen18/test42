#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mem.h"

char	**ft_split(const char *str, char ch);

void
	test(const char *str, char ch)
{
	char	**str2;
	char	**tmp;

	str2 = ft_split(str, ch);
	printf("ft_strjoin(%c) -> (", ch);
	if (str2 != NULL)
	{
		tmp = str2;
		while (*tmp != NULL)
		{
			printf("%s, ", *tmp);
			tmp += 1;
		}
	}
	printf(")\n%lu unfreed mallocs\n", mallocs - frees);
	if (str2 != NULL)
	{
#ifdef TEST_MEM
		printf("%lu malloc'd size\n", (unsigned long) malloc_size(str2));
#endif
		tmp = str2;
		while (*tmp != NULL)
		{
#ifdef TEST_MEM
			printf("%lu malloc'd size\n", (unsigned long) malloc_size(*tmp));
#endif
			free(*tmp);
			tmp += 1;
		}
		free(str2);
	}
	printf("%lu unfreed mallocs\n", mallocs - frees);
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
		seed = seed * 1103515245 + 12345;
		test(str, (char)(unsigned char)(seed >> 16));
		count -= 1;
	}
}

#ifdef TEST_EMPTY
int
	main(void)
{
	test("", ' ');
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_BASIC
int
	main(void)
{
	test("Hello, World!", ' ');
	test("Hello, World!", ',');
	test("Hello, World!", 'a');
	test("   Hello,  World!   ", ' ');
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_RANDOM
int
	main(void)
{
	test_random(0, 256);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL
int
	main(void)
{
	test(NULL, ' ');
	return (EXIT_SUCCESS);
}
#endif
