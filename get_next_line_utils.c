#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*extract_line(char *str)
{
	char	*temp;
	size_t	i;
	size_t	len;

	if (str == 0 || str[0] == 0)
		return (0);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	temp = malloc(len + 1);
	if (temp == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

char	*update_str(char *str)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == 0)
		return (free(str), NULL);
	i++;
	new = malloc(ft_strlen(str + i) + 1);
	if (new == 0)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	new[j] = 0;
	free(str);
	if (new[0] == 0)
		return (free(new), NULL);
	return (new);
}
