#include "libft.h"

static int	ft_is_set(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_set_start(char const *s1, char const *set)
{
	int		n;

	n = 0;
	while (s1[n])
	{
		if (!ft_is_set(s1[n], set))
			break ;
		n++;
	}
	return (n);
}

static int	ft_set_end(char const *s1, char const *set)
{
	size_t	i;
	int		n;

	n = 0;
	i = ft_strlen(s1);
	while (i--)
	{
		if (!ft_is_set(s1[i], set))
			break ;
		n++;
	}
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	int		start;
	int		end;
	int		j;

	j = 0;
	if (!s1 || !set)
		return (NULL);
	start = ft_set_start(s1, set);
	end = ft_set_end(s1, set);
	if ((int )ft_strlen(s1) - (start + end) <= 0)
		return (ft_strdup(""));
	arr = (char *) malloc((sizeof(char) * ft_strlen(s1) - (start + end)) + 1);
	if (!arr)
		return (NULL);
	while (j < (int )ft_strlen(s1) - start - end)
	{
		arr[j] = s1[j + start];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
