#include "../../push_swap.h"

int check_dup(char *argv[], int n)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (i <= n)
	{
		while(j <= n)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int check_char(char *argv[])
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][0] != '-' )
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int check_sp(char *argv[])
{

	int	i;
	
	i = 1;
	while (argv[i])
	{
		if (*argv[i] == '-')
		{
			if (ft_strlen(argv[i]) == 1)
				return (0);
		}
		i++;
	}
	return (1);
}

int check_dsi(char *argv[])
{

	int	i;
	int j;
	
	i = 1;
	j = 1;
	while (argv[i])
	{
		if (*argv[i] == '-')
		{
			if (ft_strlen(argv[i]) == 1)
				return (0);
			while (argv[i][j])
			{
				if	(argv[i][j] < '0' || argv[i][j] > '9')
					return (0);
				j++;
			}
		}
		i++;
		j = 1;
	}
	return (1);
}
