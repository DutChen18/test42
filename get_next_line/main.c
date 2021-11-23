#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef GNL_REOPEN
# define GNL_REOPEN 1
#endif

char	*get_next_line(int fd);

void
	test(int argc, char **argv)
{
	int		fd[OPEN_MAX];
	int		eof_count[OPEN_MAX];
	int		fd_line[OPEN_MAX];
	int		ends;
	int		n;
	int		m;
	char	*tmp;

	n = 0;
	if (argc == 0)
	{
		fd[n] = 0;
		eof_count[n] = 0;
		fd_line[n] = 0;
		n += 1;
	}
	while (n < argc)
	{
		fd[n] = open(argv[n], O_RDONLY);
		eof_count[n] = 0;
		fd_line[n] = 0;
		n += 1;
	}
	ends = 0;
	srand(0);
	while (ends < n * GNL_REOPEN)
	{
		m = rand() % n;
		if (eof_count[m] == GNL_REOPEN && (rand() % n) != 0)
			continue ;
		tmp = get_next_line(fd[m]);
		printf("<GNL %d:%d> %s\n", m, fd_line[m], tmp);
		fd_line[m] += 1;
		if (tmp == NULL)
		{
			if (eof_count[m] < GNL_REOPEN)
			{
				eof_count[m] += 1;
				ends += 1;
			}
			if (eof_count[m] < GNL_REOPEN)
			{
				close(fd[m]);
				fd[m] = open(argv[m], O_RDONLY);
				fd_line[m] = 0;
			}
		}
		free(tmp);
	}
}

int
	main(int argc, char **argv)
{
	test(argc - 1, argv + 1);
}
