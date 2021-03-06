#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t
	strlcpy2(char *dst, const char *src, size_t size)
{
	return strlcpy(dst, src, size);
}

void
	test(char *dst, const char *src, size_t size, void *writeptr, size_t writesize)
{
	size_t	res;

	printf("ft_strlcpy(%lu) -> ", (unsigned long) size);
	fflush(stdout);
	res = ft_strlcpy(dst, src, size);
	write(STDOUT_FILENO, writeptr, writesize);
	printf(", %lu)\n", (unsigned long) res);
	fflush(stdout);
}

void
	test_random(int seed, int count)
{
	int		i;
	size_t	dst;
	size_t	src;
	size_t	size;
	size_t	max;
	char	str[2048];

	while (0 < count)
	{
		seed = seed * 1103515245 + 12345;
		dst = (seed >> 16) & 2047;
		seed = seed * 1103515245 + 12345;
		src = (seed >> 16) & 2047;
		if (src == dst)
			continue;
		seed = seed * 1103515245 + 12345;
		if (seed & 65536)
		{
			dst ^= src;
			src ^= dst;
			dst ^= src;
		}
		i = 0;
		while (i < 2048)
		{
			seed = seed * 1103515245 + 12345;
			str[i] = (char)(unsigned char)(seed >> 16);
			i += 1;
		}
		if (src > dst)
		{
			max = src - dst;
			str[2047] = '\0';
		}
		else
		{
			max = 2048 - dst;
			str[dst - 1] = '\0';
		}
		seed = seed * 1103515245 + 12345;
		size = (size_t) (seed >> 16) % (max + 1);
		test(str + dst, str + src, size, str, 2048);
		count -= 1;
	}
}

void
	main_empty(void)
{
	test("", (void *) "", 0, "", 0);
}

void
	main_null1(void)
{
	char	str[1];

	str[0] = '*';
	test(NULL, str, 1, str, 1);
}

void
	main_null2(void)
{
	char	str[1];

	str[0] = '*';
	test(str, NULL, 1, str, 1);
}

void
	main_null3(void)
{
	char	str[1];

	str[0] = '*';
	test(NULL, NULL, 1, str, 1);
}

void
	main_random(void)
{
	test_random(0, 256);
}
