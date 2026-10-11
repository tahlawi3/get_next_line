#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		*fds;
	char	*line;
	int		i;
	int		finished;

	if (argc < 2)
	{
		printf("Usage: %s <file1> <file2> <file3> ...\n", argv[0]);
		return (1);
	}
	fds = malloc(sizeof(int) * (argc - 1));
	if (!fds)
		return (1);
	i = 1;
	while (i < argc)
	{
		fds[i - 1] = open(argv[i], O_RDONLY);
		if (fds[i - 1] < 0)
			perror("open error");
		i++;
	}
	finished = 0;
	while (finished < argc - 1)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (fds[i] != -1)
			{
				line = get_next_line(fds[i]);
				if (line)
				{
					printf("[%s]: %s", argv[i + 1], line);
					free(line);
				}
				else
				{
					close(fds[i]);
					fds[i] = -1;
					finished++;
				}
			}
			i++;
		}
	}
	free(fds);
	return (0);
}
