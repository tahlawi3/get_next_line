
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test_read.c", O_WRONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
