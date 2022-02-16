#include "../../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*old_elem;

	while (*lst)
	{
		old_elem = *lst;
		*lst = old_elem->next;
		free(old_elem);
	}
	*lst = NULL;
}
