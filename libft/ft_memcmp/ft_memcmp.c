#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_memcmp(const void *str1, const void *str2, size_t len);

void
	test(const void *str1, const void *str2, size_t size)
{
	int	res;

	printf("ft_memcmp(%lu) -> ", (unsigned long) size);
	fflush(stdout);
	res = ft_memcmp(str1, str2, size);
	printf("%d\n", res);
}

void
	test_random(int seed, int count)
{
	int		i;
	size_t	str1;
	size_t	str2;
	size_t	size;
	char	str[2048 + 32];

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
		size = (size_t) (seed >> 16) & 31;
		while (0 < size)
		{
			size -= 1;
			str[str1 + size] = str[str2 = size];
		}
		seed = seed * 1103515245 + 12345;
		size = (size_t) (seed >> 16) & 31;
		test(str + str1, str + str2, size);
		count -= 1;
	}
}

void
	main_empty(void)
{
	test("", "", 0);
	test("abc", "", 0);
	test("", "abc", 0);
}

void
	main_null1(void)
{
	test("abc", NULL, 10);
	test(NULL, "abc", 10);
	test(NULL, NULL, 10);
}

void
	main_null2(void)
{
	test("abc", NULL, 0);
	test(NULL, "abc", 0);
	test(NULL, NULL, 0);
}

void
	main_basic(void)
{
	test("123", "123", 0);
	test("123abc", "123", 0);
	test("123", "123abc", 0);
	test("123", "123", 3);
	test("123abc", "123", 3);
	test("123", "123abc", 3);
	test("123", "123", 4);
	test("123abc", "123", 4);
	test("123", "123abc", 4);
}

void
	main_random(void)
{
	test_random(0, 256);
}
