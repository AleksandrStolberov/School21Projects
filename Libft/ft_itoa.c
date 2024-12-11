#include "libft.h"

static int	ft_count(long n, int nb)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (nb < 0)
		i++;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void	ft_rev(char *arr)
{
	char	tmp;
	int		i;
	int		n;

	i = 0;
	n = (int)ft_strlen(arr);
	while (i < (n / 2))
	{
		tmp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = tmp;
		i++;
	}
}

static long	ft_num_neg(int n)
{
	if (n == -2147483648)
		return (2147483648);
	else if (n < 0)
		return (n * (-1));
	return (n);
}

static void	ft_sign(char *arr, int n, int j)
{
	if (n < 0)
	{
		arr[j] = '-';
		arr[j + 1] = '\0';
	}
	else if (n == 0)
	{
		arr[j] = '0';
		arr[j + 1] = '\0';
	}
	else
		arr[j] = '\0';
}

char	*ft_itoa(int n)
{
	char		*arr;
	int			j;
	long		num;

	j = 0;
	num = ft_num_neg(n);
	arr = (char *) malloc(sizeof(char) * ft_count(num, n) + 1);
	if (!arr)
		return (NULL);
	while (num > 0)
	{
		arr[j++] = num % 10 + '0';
		num /= 10;
	}
	ft_sign(arr, n, j);
	ft_rev(arr);
	return (arr);
}
