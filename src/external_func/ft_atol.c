/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:57:15 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 18:04:00 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

void	err_handling(char str)
{
	if (is_charset(str) != -1)
	{
		write(2, "Error atol\n", 12);
		exit(1);
	}
}

void	max_min_int(long nb)
{
	if (nb > 2147483647)
	{
		write(2, "Error\n", 7);
		exit(0);
	}
	if (nb < -2147483648)
	{
		write(2, "Error\n", 7);
		exit(0);
	}
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
		err_handling(str[i]);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = nb * sign;
	max_min_int(nb);
	return (nb);
}
