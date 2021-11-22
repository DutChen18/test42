#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd);

int
	main(int argc, char **argv)
{
	int		fd[OPEN_MAX];
	int		ended[OPEN_MAX];
	int		n;
	int		ends;
	int		tmpfd;
	char	*tmp;

	n = 0;
	if (argc == 1)
	{
		fd[n] = 0;
		ended[0] = 0;
		n += 1;
	}
	while (n < argc - 1)
	{
		fd[n] = open(argv[n + 1], O_RDONLY);
		ended[fd[n]] = 0;
		n += 1;
	}
	ends = 0;
	srand(0);
	while (ends < n)
	{
		tmpfd = fd[rand() % n];
		if (ended[tmpfd] && (rand() % n) != 0)
			continue ;
		tmp = get_next_line(tmpfd);
		printf("<GNL> %s\n", tmp);
		if (tmp == NULL)
		{
			if (!ended[tmpfd])
				ends += 1;
			ended[tmpfd] = 1;
		}
		free(tmp);
	}
}
