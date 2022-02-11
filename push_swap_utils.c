#include "push_swap.h"

void swap_a(t_list  **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (ft_lstsize(*list) >= 2)
	{
		tmp = *list;
		tmp2 = (*list)->next->next;
		*list = (*list)->next;
		(*list)->next = tmp;
		tmp->next = tmp2;
	}
    write (1, "sa\n", 3);
}

void swap_b(t_list  **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (ft_lstsize(*list) >= 2)
	{
		tmp = *list;
		tmp2 = (*list)->next->next;
		*list = (*list)->next;
		(*list)->next = tmp;
		tmp->next = tmp2;
	}
    write (1, "sb\n", 3);
}

void ss(t_list *a, t_list *b)
{
    swap_a(&a);
    swap_b(&b);
    write (1, "ss\n", 3);
}

void push_a(t_list **list_p, t_list **list_t)
{
	t_list	*temp;
	t_list	*temp2;

	if (*list_t == NULL)
		return ;
	else
	{
		temp = (*list_t);
		temp2 = (*list_p);
		*list_t = (*list_t)->next;
		*list_p = temp;
		temp->next = temp2;
	} 
    write(1, "pa\n", 3);
}

void push_b(t_list **list_p, t_list **list_t)
{
	t_list	*temp;
	t_list	*temp2;

	if (*list_t == NULL)
		return ;
	else
	{
		temp = (*list_t);
		temp2 = (*list_p);
		*list_t = (*list_t)->next;
		*list_p = temp;
		temp->next = temp2;
	} 
    write(1, "pb\n", 3);
}
