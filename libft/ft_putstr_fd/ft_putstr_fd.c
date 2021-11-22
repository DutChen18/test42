#include <stdio.h>
#include <stdlib.h>

void	ft_putstr_fd(const char *str, int fd);

void
	test(const char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd(str, 2);
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
	main_null(void)
{
	test(NULL);
}

void
	main_basic(void)
{
	test("Hello, World!\n");
	test("42\n");
	test("test\n");
}

void
	main_random(void)
{
	test_random(0, 256);
}
