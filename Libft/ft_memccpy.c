#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	new_dest = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		if (*new_src == (unsigned char)c)
		{
			*new_dest = (unsigned char)c;
			return (dst + i + 1);
		}
		*new_dest++ = *new_src++;
		i++;
	}
	return (NULL);
}
