#include "push_swap.h"

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
	
	while (is_charset(str[i]) == 1)
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (is_charset(str[i]) != -1)
		{
			write(2, "Error atol\n", 12);
			exit(1);
			break;	
		}
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = nb *sign;
	if (nb >= 2147483647)
	{
		printf("Error, int max\n");
		exit(0);
	}
	if (nb <= -2147483648)
	{
		printf("Error, int min\n");
		exit(0);
	}
	return (nb);
}