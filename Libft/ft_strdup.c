#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	char	*arr;
	int		n;

	n = 0;
	while (s1[n] != '\0')
		n++;
	arr = (char *)malloc(n + 1);
	if (!arr)
		return (NULL);
	a = arr;
	while (*s1)
		*a++ = *s1++;
	*a = '\0';
	return (arr);
}
