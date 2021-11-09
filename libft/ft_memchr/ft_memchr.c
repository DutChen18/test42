#include <stdio.h>
#include <stdlib.h>

void	*ft_memchr(const void *str, int ch, size_t size);

void
	test(const void *str, int ch, size_t size)
{
	char	*res;

	res = ft_memchr(str, ch, size);
	if (res == NULL)
		printf("ft_strchr(%lu) -> (null)\n", (unsigned long) size);
	else
		printf("ft_strchr(%lu) -> %lu\n", (unsigned long) size, (unsigned long)((char *) res - (char *) str));
}

void
	test_random(int seed, int count)
{
	int		i;
	char	str[2048];
	size_t	size;

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
		size = (seed >> 16) & 2047;
		seed = seed * 1103515245 + 12345;
		test(str, seed >> 24, size);
		test(str, -(seed >> 24), size);
		test(str, seed >> 20, size);
		test(str, -(seed >> 20), size);
		count -= 1;
	}
}

#ifdef TEST_EMPTY
int
	main(void)
{
	test("", '\0', 1);
	test("", 'a', 1);
	test("", '\0', 0);
	test("", 'a', 0);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL
int
	main(void)
{
	test(NULL, 'a', 0);
	test(NULL, 'a', 1);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_BASIC
int
	main(void)
{
	test("Hello, World!", ',', 5);
	test("Hello, World!", ',', 6);
	test("Hello, World!", ',', 7);
	test("Hello, World!", 'J', 13);
	test("Hello, World!", 'J', 14);
	test("Hello, World!", '\0', 12);
	test("Hello, World!", '\0', 13);
	test("Hello, World!", '\0', 14);
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
