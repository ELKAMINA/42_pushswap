#include "push_swap.h"

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

int check_space_with_minus(char *argv[])
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

int check_double_signs(char *argv[])
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

void	ft_exit(t_list *list)
{
	if (!list)
	{
		printf("error malloc\n");
		exit(0);
	}
}

t_list *create_A(int argc, char *argv[])
{
	int i;
	int n;
	t_list *head_A;
	t_list *current_A;

	n = argc - 1;
	i = 3;
	if (n == 1)
	{
		head_A = ft_lstnew((int)ft_atol(argv[1]));
		ft_exit(head_A);
		head_A->next = NULL;
		head_A->previous = NULL;
	}
	else 
	{
		head_A = ft_lstnew((int)ft_atol(argv[1]));
		ft_exit(head_A);
		current_A = ft_lstnew((int)ft_atol(argv[2]));
		ft_exit(current_A);
		head_A -> next = current_A;
		current_A -> previous = head_A;
		while (i <= n)
		{
			current_A = ft_lstnew((int)ft_atol(argv[i]));
			ft_exit(current_A);
			ft_lstadd_back(&head_A, current_A);
			i++;
		}
	}
	return (head_A);
}

// void	print_lst(t_list  *start)
// {
// 	t_list *temp;

// 	temp = start;

// 	while (temp)
// 	{

// 		printf("DATA = [%d] \n", temp->data);
// 		temp = temp->next;
// 	}
// }

int main (int   argc, char  *argv[])
{
	int n;
	t_list *head_A;
	t_list *head_B;

	n = argc - 1;
	if (argc < 2)
		return 0;
	if	(check_dup(argv, n) == 0 || check_char(argv) == 0 || check_space_with_minus(argv) == 0 || check_double_signs(argv) == 0) 
	{
		write (2, "Error\n", 7);
		return 0;
	}
	else 
	{
		head_A = create_A(argc, argv);
		head_B = NULL;	
		if	(argc == 3)
			sorting_two(&head_A);	
		else if	(argc == 4)
			sorting_three(&head_A);	
		else if	(argc == 5)
			sorting_four(&head_A, &head_B);
		else if	(argc == 6)
			sorting_five(&head_A, &head_B);
		else
			sorting_above_five(&head_A, &head_B);
	// write(1, "A\n", 2);
	// print_lst(head_A);
	// write(1, "B\n", 2);
	// print_lst(head_B);
	ft_lstclear(&head_A);
}
	return 0 ;
}
