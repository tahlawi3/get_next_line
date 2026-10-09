#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*read_to_str(int fd, char *str);
char	*extract_line(char *str);
char	*update_str(char *str);
size_t	ft_strlen(const char *s);
#endif
