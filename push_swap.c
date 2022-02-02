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

t_list *create_A(int argc, char *argv[])
{
	int i;
	int n;
	t_list *head_A;
	t_list *current_A;

	n = argc - 1;
	i = 3;
	//printf("%d", n);
	head_A = ft_lstnew((int)ft_atol(argv[1]));
	current_A = ft_lstnew((int)ft_atol(argv[2]));
	head_A -> next = current_A;
	current_A -> previous = head_A;
	while (i <= n)
	{
		current_A = ft_lstnew((int)ft_atol(argv[i]));
		ft_lstadd_back(&head_A, current_A);
		i++;
	}
	//je recupere et je parse mes arguments et je les affiche
	return (head_A);
}

t_list *create_B()
{
	t_list *head_B;

	head_B = ft_lstnew(0);
	return (head_B);
}

void	print_lst(t_list  *start)
{
	t_list *temp;

	temp = start;
	while (temp)
	{
		printf("[%d]\n", temp->data);
		temp = temp->next;
	}
}

int main (int   argc, char  *argv[])
{
	int n;
	t_list *head_A;
	t_list *head_B;

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
		head_A = create_A(argc, argv);
		head_B = NULL;
		//swap_a(&head_A);
		// swap_b(head_B);
		//push_a(&head_A, &head_B);
		//push_b(&head_B, &head_A);
		//rotate_a(&head_A);
		//rev_rotate_a(&head_A);
		//rev_rotate_b(&head_B);
		// if	(argc > 2 && argc < 5)
		// 	sorting_three(&head_A);	
		// if	(argc > 3 && argc < 6)
		// 	sorting_four(&head_A, &head_B);
		// if	(argc > 4 && argc < 7)
		// {
		// 	sorting_five(&head_A, &head_B);
		// 	// sorting_three(&head_A);
		// 	// push_a(&head_A, &head_B);
		// }
		if	(argc > 5 && argc < 100)
		{
			sorting_under_hundred(&head_A, &head_B);
			// sorting_three(&head_A);
			// push_a(&head_A, &head_B);
		}
		//print_lst(head_B);
		//print_lst(head_B);
		// printf("%d", higher(&head_A));
		// printf("%d", lower(&head_A));
	}
	return 0 ;
}
