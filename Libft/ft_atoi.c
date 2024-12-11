#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	num;
	int			neg;

	neg = 0;
	num = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r'
		   || *str == ' ' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += (long int)*str - '0';
		str++;
	}
	if (neg == 1)
		return ((int) -num);
	return ((int)num);
}
