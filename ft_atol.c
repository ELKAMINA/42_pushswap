long	ft_atol(const char *str)
{
	long	i;
	long	neg;
	long	r;

	i = 0;
	neg = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i ++;
		if (r * neg > 2147483647)
			return (-1);
		if (r * neg < -2147483648)
			return (0);
	}
	return (r * neg);
}
