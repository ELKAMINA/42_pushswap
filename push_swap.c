#include "push_swap.h"

int main (int   argc, char  *argv[])
{
	int i;
	int n;
	t_list *head;
	t_list *current;

	if (argc < 2)
		return 0;
	n = argc - 1;
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
	// je recupere et je parse mes arguments
	while (head != NULL)
	{ 
		printf("%d\n", head -> data);
		head = head -> next;
	}
	return 0 ;
}
