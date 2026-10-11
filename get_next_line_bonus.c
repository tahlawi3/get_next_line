#include "get_next_line_bonus.h"

static t_list	*get_node(t_list **head, int fd)
{
	t_list	*cur;
	t_list	*new_node;

	cur = *head;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->content = NULL;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

char	*read_file(char *str, int fd)
{
	char	*res;
	int		bytes;
	char	*tmp;

	if (!str)
		str = ft_calloc(1, 1);
	res = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!res)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(str, '\n'))
	{
		bytes = read(fd, res, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(str);
			str = NULL;
			break ;
		}
		res[bytes] = '\0';
		tmp = ft_strjoin(str, res);
		free(str);
		str = tmp;
	}
	free(res);
	return (str);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(i + 1 + (str[i] == '\n'), 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	return (line);
}

static void	remove_node(t_list **head, int fd)
{
	t_list	*cur;
	t_list	*prev;

	cur = *head;
	prev = NULL;
	while (cur)
	{
		if (cur->fd == fd)
		{
			if (prev)
				prev->next = cur->next;
			else
				*head = cur->next;
			if (cur->content)
			{
				free(cur->content);
				cur->content = NULL;
			}
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*line;
	t_list			*cur;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	cur = get_node(&head, fd);
	if (!cur)
		return (NULL);
	cur->content = read_file(cur->content, fd);
	if (!cur->content)
	{
		remove_node(&head, fd);
		return (NULL);
	}
	line = get_line(cur->content);
	if (!line)
	{
		remove_node(&head, fd);
		return (NULL);
	}
	cur->content = new_str(cur->content);
	if (!cur->content)
		remove_node(&head, fd);
	return (line);
}
