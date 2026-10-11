#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;

	printf("Enter text (Ctrl+D to exit):\n");
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		printf("You typed: %s", line);
		free(line);
	}
	printf("\nEnd of input (EOF reached).\n");
	return (0);
}
