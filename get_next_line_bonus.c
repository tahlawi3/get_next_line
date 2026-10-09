#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == 0)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}

char	*read_to_str(int fd, char *str)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes;

	if (str == 0)
	{
		str = malloc(1);
		if (str == 0)
			return (0);
		str[0] = 0;
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == 0)
		return (free(str), NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(str), NULL);
		buffer[bytes] = 0;
		if (bytes > 0)
		{
			temp = ft_strjoin(str, buffer);
			if (temp == 0)
				return (free(buffer), free(str), NULL);
			free(str);
			str = temp;
		}
	}
	free(buffer);
	return (str);
}

t_str	*find_fd(t_str **file, int fd)
{
	t_str	*cur;

	cur = *file;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	cur = malloc(sizeof(t_str));
	if (cur == 0)
		return (0);
	cur->fd = fd;
	cur->str = NULL;
	cur->next = *file;
	*file = cur;
	return (cur);
}

char	*get_next_line(int fd)
{
	static t_str	*file;
	t_str	*cur;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	cur = find_fd(&file, fd);
	if (cur == 0)
		return (0);
	cur->str = read_to_str(fd, cur->str);
	if (cur->str == 0)
	{
		remove_fd(&file, fd);
		return (0);
	}
	line = extract_line(cur->str);
	if (line == 0)
	{
		remove_fd(&file, fd);
		return (0);
	}
	cur->str = update_str(cur->str);
	return (line);
}
