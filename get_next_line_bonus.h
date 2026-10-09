#ifndef GET_NEXT_LINE_BOUNS_H
# define GET_NEXT_LINE_BOUNS_H
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct	s_str
{
	int		fd;
	char	*str;
	struct s_str	*next;
}	t_str;
t_str	*find_fd(t_str **file, int fd);
char	*get_next_line(int fd);
char	*read_to_str(int fd, char *str);
char	*extract_line(char *str);
char	*update_str(char *str);
size_t	ft_strlen(const char *s);
void	remove_fd(t_str **file, int fd);
#endif
