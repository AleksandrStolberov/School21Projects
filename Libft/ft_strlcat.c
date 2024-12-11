#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	d;
	size_t	len_s;

	d = 0;
	len_s = ft_strlen(src);
	while (dst[d] != '\0' && d < dstsize)
		d++;
	s = 0;
	while (src[s] != '\0' && d + s + 1 < dstsize)
	{
		dst[d + s] = src[s];
		s++;
	}
	if (d != dstsize)
		dst[d + s] = '\0';
	return (d + len_s);
}
