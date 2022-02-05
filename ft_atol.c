#include "push_swap.h"

// long	ft_atol(const char *str)
// {
// 	long	i;
// 	long	neg;
// 	long	r;

// 	i = 0;
// 	neg = 1;
// 	r = 0;
// 	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			neg = -1;
// 		i++;
// 	}
// 	while (str[i] && str[i] >= '0' && str[i] <= '9')
// 	{
// 		r = r * 10 + (str[i] - 48);
// 		i ++;
// 		if (r * neg > 2147483647)
// 			return (-1);
// 		if (r * neg < -2147483648)
// 			return (0);
// 	}
// 	return (r * neg);
// }

int	is_charset(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\n'
		|| c == '\r' || c == ' ')
		return (0);
	else if (c == '-' || c == '+')
		return (1);
	else
		return (-1);
}

long	ft_atol(const char	*str)
{
	long		i;
	long		sign;
	long		nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (is_charset(str[i]) == 0)
		i++;
	while (is_charset(str[i]) == 1)
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
		// if (nb * sign > 2147483647 || nb * sign < -2147483648)
		// {
		// 	write(2, "Error\n", 6);
		// 	break ;
		// }
	}
	return (nb * sign);
}