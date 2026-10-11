#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}			t_list;

char	*get_next_line(int fd);
char	*read_file(char *str, int fd);
char	*get_line(char *content);
char	*new_str(char *content);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*copy_str(char *str, int i);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);

#endif
