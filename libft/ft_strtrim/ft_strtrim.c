#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mem.h"

char	*ft_strtrim(const char *str1, const char *str2);

void
	test(const char *str1, const char *str2)
{
	char	*str3;

	str3 = ft_strtrim(str1, str2);
	printf("ft_strtrim() -> %s\n", str3);
	printf("%lu unfreed mallocs\n", mallocs - frees);
	if (str3 != NULL)
	{
#ifdef TEST_MEM
		printf("%lu malloc'd size\n", (unsigned long) malloc_size(str3));
#endif
		free(str3);
	}
	printf("%lu unfreed mallocs\n", mallocs - frees);
}

void
	test_random(int seed, int count)
{
	int		i;
	char	str[2049];
	size_t	str1;
	size_t	str2;

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
		str1 = seed & 2047;
		seed = seed * 1103515245 + 12345;
		str2 = seed & 2047;
		test(str + str1, str + str2);
		count -= 1;
	}
}

#ifdef TEST_EMPTY
int
	main(void)
{
	test("", "");
	test("", "a");
	test("a", "");
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_BASIC
int
	main(void)
{
	test("Hello, World!", "He!");
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
	test(NULL, "");
	test("", NULL);
	test(NULL, NULL);
	return (EXIT_SUCCESS);
}
#endif
