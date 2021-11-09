#include <stdio.h>
#include <stdlib.h>

char	*ft_strrchr(const char *str, int ch);

void
	test(const char *str, int ch)
{
	char	*res;

	res = ft_strrchr(str, ch);
	if (res == NULL)
		printf("ft_strrchr() -> (null)\n");
	else
		printf("ft_strrchr() -> %lu\n", (unsigned long)((char *) res - (char *) str));
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
		test(str, seed >> 24);
		test(str, -(seed >> 24));
		test(str, seed >> 20);
		test(str, -(seed >> 20));
		count -= 1;
	}
}

#ifdef TEST_EMPTY
int
	main(void)
{
	test("", '\0');
	test("", 'a');
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL
int
	main(void)
{
	test(NULL, 'a');
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_BASIC
int
	main(void)
{
	test("Hello, World!", ',');
	test("Hello, World!", 'J');
	test("Hello, World!", '\0');
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
