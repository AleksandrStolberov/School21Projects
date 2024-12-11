#include "libft.h"

static unsigned int	ft_array_count(char const *s, char c)
{
	unsigned int		n;
	unsigned int		i;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static char	**ft_free(char **arr, char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (i < ft_array_count(s, c))
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static unsigned int	ft_length(char const *s, unsigned int *len, char c)
{
	unsigned int		i;
	unsigned int		n;
	unsigned int		end;

	n = 0;
	i = 0;
	while (*s == c)
		s++;
	while (s[*len] && s[*len] != c)
	{
		i++;
		(*len)++;
	}
	end = *len;
	while (s[end] == c)
	{
		n++;
		end++;
	}
	*len += n;
	return (i);
}

static unsigned int	ft_new_string(char *arr, char const *s, unsigned int n,
								  char c)
{
	unsigned int		i;
	unsigned int		v;
	unsigned int		st;

	i = 0;
	v = 0;
	st = 0;
	while (s[n + v] == c)
		v++;
	st = ft_length(s + n, &st, c);
	while (i < st)
	{
		arr[i] = s[i + v + n];
		i++;
	}
	arr[i] = '\0';
	return (v);
}

char	**ft_split(char const *s, char c)
{
	char				**arr;
	unsigned int		i;
	unsigned int		n;
	unsigned int		start;
	unsigned int		len;

	if (!s)
		return (NULL);
	start = 0;
	i = 0;
	n = 0;
	arr = (char **) malloc(sizeof(char *) * ft_array_count(s, c) + 1);
	if (!arr)
		return (NULL);
	while (i < ft_array_count(s, c))
	{
		len = ft_length(s, &start, c);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!arr[i])
			return (ft_free(arr, s, c));
		n += ft_new_string(arr[i], s, n, c) + len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
