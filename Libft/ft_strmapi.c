#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*arr;
	unsigned int	n;

	n = 0;
	if (!s)
		return (NULL);
	arr = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!arr)
		return (NULL);
	while (s[n])
	{
		arr[n] = f(n, s[n]);
		n++;
	}
	arr[n] = '\0';
	return (arr);
}
