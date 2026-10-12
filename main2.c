#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (perror("open"), 1);
	line = get_next_line(fd1);
	printf("fd1: %s", line ? line : "EOF\n");
	free(line);
	line = get_next_line(fd2);
	printf("fd2: %s", line ? line : "EOF\n");
	free(line);
	line = get_next_line(fd3);
	printf("fd3: %s", line ? line : "EOF\n");
	free(line);
	line = get_next_line(fd1);
	printf("fd1: %s", line ? line : "EOF\n");
	free(line);
	line = get_next_line(fd2);
	printf("fd2: %s", line ? line : "EOF\n");
	free(line);
	line = get_next_line(fd3);
	printf("fd3: %s", line ? line : "EOF\n");
	free(line);
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("fd1: %s", line);
		free(line);
	}
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("fd2: %s", line);
		free(line);
	}
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("fd3: %s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
