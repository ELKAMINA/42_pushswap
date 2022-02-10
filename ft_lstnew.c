
#include "push_swap.h"

t_list	*ft_lstnew(int	argument)
{
	t_list	*new;

	new = malloc(sizeof (t_list));
	if (new == NULL)
		return (NULL);
	new -> data = argument;
	new -> next = NULL;
	new -> previous = NULL;
	new->sort = 1;
	new->boolean = 'F';
	new->posinA = 1;
	new->pos = 1;
	new->moves = 0;
	return (new);
}
