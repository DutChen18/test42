#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t size);

void
	*memmove2(void *dst, const void *src, size_t size)
{
	return memmove(dst, src, size);
}

void
	test(void *dst, const void *src, size_t size, void *writeptr, size_t writesize)
{
	void	*res;

	printf("ft_memmove(");
	fflush(stdout);
	write(STDOUT_FILENO, writeptr, writesize);
	printf(", %lu) -> ", (unsigned long) size);
	fflush(stdout);
	res = ft_memmove(dst, src, size);
	write(STDOUT_FILENO, writeptr, writesize);
	printf(", %lu)\n", (unsigned long)((char *) res - (char *) dst));
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
	char	str[256];

	while (0 < count)
	{
		seed = seed * 1103515245 + 12345;
		dst = seed & 255;
		seed = seed * 1103515245 + 12345;
		src = seed & 255;
		max = 256 - dst;
		if (256 - src < max)
			max = 256 - src;
		seed = seed * 1103515245 + 12345;
		size = (unsigned int) seed % (max + 1);
		i = 0;
		while (i < 256)
		{
			seed = seed * 1103515245 + 12345;
			str[i] = (char)(unsigned char)(seed >> 16);
			i += 1;
		}
		test(str + dst, str + src, size, str, 256);
		count -= 1;
	}
}

#ifdef TEST_EMPTY
int
	main(void)
{
	test("", (void *) "", 0, "", 0);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL1
int
	main(void)
{
	char	str[1];

	str[0] = '*';
	test(NULL, str, 1, str, 1);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL2
int
	main(void)
{
	char	str[1];

	str[0] = '*';
	test(str, NULL, 1, str, 1);
	return (EXIT_SUCCESS);
}
#endif

#ifdef TEST_NULL3
int
	main(void)
{
	char	str[1];

	str[0] = '*';
	test(NULL, NULL, 1, str, 1);
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
