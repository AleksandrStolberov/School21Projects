#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if ((!*haystack && !*needle) || !*needle)
		return ((char *)haystack);
	if (ft_strlen(haystack) == 0 || len == 0)
		return (NULL);
	while (haystack[i] != '\0' && i < len)
	{
		n = 0;
		while (haystack[i + n] != '\0' && needle[n] != '\0' && i + n < len
			   && haystack[i + n] == needle[n])
			n++;
		if (!needle[n])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
