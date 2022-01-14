#include "push_swap.h"

int	check_args(char	*argv[])
{
	int	i; 

	i = 1;
	while (argv[i])
	{
		if	(*argv[i] < 48 || *argv[i] > 57)
			return (0);
		i ++;
	}
	return (1);
}

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

int main (int   argc, char  *argv[])
{
	int i;
	int n;
	t_list *head;
	t_list *current;

	n = argc - 1;
	if (argc < 2)
		return 0;
	if	(check_args(argv) == 0 || check_dup(argv, n) == 0)
	{
		write (2, "Error\n", 6);
		return 0;
	}
	else 
	{
		i = 3;
		head = ft_lstnew((int)ft_atol(argv[1]));
		current = ft_lstnew((int)ft_atol(argv[2]));
		head -> next = current;
		current -> previous = head;
		while (i <= n)
		{
			current = ft_lstnew((int)ft_atol(argv[i]));
			ft_lstadd_back(&head, current);
			i++;
		}
		//je recupere et je parse mes arguments
		// while (head != NULL)
		// { 
		// 	printf("%d\n", head -> data);
		// 	head = head -> next;
		// }

	}
	return 0 ;
}
