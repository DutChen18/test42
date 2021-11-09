#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);

void
	test(const char *str)
{
	unsigned long	len;

	len = (unsigned long) ft_strlen(str);
	printf("ft_strlen(%s) -> %lu\n", str, len);
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

#ifdef TEST_EMPTY
int
	main(void)
{
	test("");
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL
int
	main(void)
{
	test(NULL);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_BASIC
int
	main(void)
{
	test("Hello, World!");
	test("42");
	test("test");
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
