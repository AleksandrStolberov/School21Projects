#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	arr = (char *) malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
		return (NULL);
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		arr[i] = s2[n];
		i++;
		n++;
	}
	arr[i] = '\0';
	return (arr);
}
