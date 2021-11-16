#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*ft_strnstr(const char *str1, const char *str2, size_t len);

void
	test(const char *str1, const char *str2, size_t size)
{
	char	*res;

	printf("ft_strnstr(%lu) -> ", (unsigned long) size);
	fflush(stdout);
	res = ft_strnstr(str1, str2, size);
	if (res == NULL)
		printf("(null)\n");
	else
		printf("%lu\n", (unsigned long)(res - str1));
}

void
	test_random(int seed, int count)
{
	int		i;
	size_t	str1;
	size_t	str2;
	size_t	size;
	size_t	offset;
	char	str[2048 + 32 + 257];

	str[2048 + 32] = '\0';
	while (0 < count)
	{
		seed = seed * 1103515245 + 12345;
		str1 = (seed >> 16) & 2047;
		seed = seed * 1103515245 + 12345;
		str2 = (seed >> 16) & 2047;
		i = 0;
		while (i < 2048)
		{
			seed = seed * 1103515245 + 12345;
			str[i] = (char)(unsigned char)(seed >> 16);
			i += 1;
		}
		seed = seed * 1103515245 + 12345;
		size = (seed >> 16) & 31;
		seed = seed * 1103515245 + 12345;
		offset = (seed >> 16) & 255;
		while (0 < size)
		{
			size -= 1;
			str[str1 + size + offset] = str[str2 + size];
		}
		seed = seed * 1103515245 + 12345;
		size = (seed >> 16) & 2047;
		test(str + str1, str + str2, size);
		count -= 1;
	}
}

#ifdef TEST_EMPTY
int
	main(void)
{
	test("", "", 10);
	test("abc", "", 10);
	test("", "abc", 10);
	test("", "", 0);
	test("abc", "", 0);
	test("", "abc", 0);
	test("", "", 3);
	test("abc", "", 3);
	test("", "abc", 3);
	test("", "", 4);
	test("abc", "", 4);
	test("", "abc", 4);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL1
int
	main(void)
{
	test("abc", NULL, 10);
	test(NULL, "abc", 10);
	test(NULL, NULL, 10);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL2
int
	main(void)
{
	test("abc", NULL, 0);
	test(NULL, "abc", 0);
	test(NULL, NULL, 0);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_BASIC
int
	main(void)
{
	test("123", "123", 10);
	test("123abc", "123", 10);
	test("123", "123abc", 10);
	test("123", "123", 0);
	test("123abc", "123", 0);
	test("123", "123abc", 0);
	test("123", "123", 3);
	test("123abc", "123", 3);
	test("123", "123abc", 3);
	test("123", "123", 4);
	test("123abc", "123", 4);
	test("123", "123abc", 4);
	test("123", "123", 6);
	test("123abc", "123", 6);
	test("123", "123abc", 6);
	test("123", "123", 7);
	test("123abc", "123", 7);
	test("123", "123abc", 7);
	test("123", "123", 10);
	test("123abc", "123", 10);
	test("123", "abc123", 10);
	test("123", "123", 0);
	test("abc123", "123", 0);
	test("123", "abc123", 0);
	test("123", "123", 3);
	test("abc123", "123", 3);
	test("123", "abc123", 3);
	test("123", "123", 4);
	test("abc123", "123", 4);
	test("123", "abc123", 4);
	test("123", "123", 6);
	test("abc123", "123", 6);
	test("123", "abc123", 6);
	test("123", "123", 7);
	test("abc123", "123", 7);
	test("123", "abc123", 7);
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
