/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tahlawi3 <tahlawi3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:51:38 by tahlawi3          #+#    #+#             */
/*   Updated: 2026/10/12 15:51:39 by tahlawi3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_str(char *str)
{
	char	*ans;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	ans = copy_str(str, i);
	free(str);
	return (ans);
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
	line = malloc(i + 1 + (str[i] == '\n'));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

static char	*read_buffer(int fd, char *str, char *res, int *bytes)
{
	char	*temp;

	*bytes = read(fd, res, BUFFER_SIZE);
	if (*bytes < 0)
	{
		free(str);
		return (NULL);
	}
	if (*bytes == 0)
		return (str);
	res[*bytes] = 0;
	temp = ft_strjoin(str, res);
	free(str);
	return (temp);
}

char	*read_file(char *str, int fd)
{
	char	*res;
	int		bytes;

	str = check_str(str);
	if (!str)
		return (NULL);
	res = malloc(BUFFER_SIZE + 1);
	if (!res)
	{
		free(str);
		return (NULL);
	}
	bytes = 1;
	while (bytes != 0 && !ft_strchr(str, '\n'))
	{
		str = read_buffer(fd, str, res, &bytes);
		if (!str)
			break ;
	}
	free(res);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	str = read_file(str, fd);
	if (!str)
		return (NULL);
	line = get_line(str);
	if (!line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = new_str(str);
	return (line);
}
