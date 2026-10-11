#include "get_next_line.h"

char	*copy_str(char *str, int i)
{
	char	*ans;
	int		j;

	ans = ft_calloc(ft_strlen(str) - i, 1);
	if (!ans)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
	{
		ans[j] = str[i];
		j++;
		i++;
	}
	return (ans);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*p;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < count * size)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}
