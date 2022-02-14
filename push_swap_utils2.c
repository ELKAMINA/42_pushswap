#include "push_swap.h"

void rotate_a(t_list **list)
{
	t_list	*curs;
	t_list	*tmp;

	if (*list == NULL)
		return ;
	else
	{
		tmp = (*list);
		curs = (*list);
		*list = (*list)->next;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = tmp;
		tmp->next = NULL;
	}
    write(1, "ra\n", 3);
}

void rotate_b(t_list **list)
{
	t_list	*curs;
	t_list	*tmp;

	if (*list == NULL)
		return ;
	else
	{
		tmp = (*list);
		curs = (*list);
		*list = (*list)->next;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = tmp;
		tmp->next = NULL;
	}
    write(1, "rb\n", 3);
}


void rr(t_list **list_a, t_list **list_b)
{
	t_list	*curs;
	t_list	*tmp;

	if (*list_a)
	{
		tmp = (*list_a);
		curs = (*list_a);
		*list_a = (*list_a)->next;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = tmp;
		tmp->next = NULL;
	}
	if (*list_b)
	{
		tmp = (*list_b);
		curs = (*list_b);
		*list_b = (*list_b)->next;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = tmp;
		 tmp->next = NULL;
	}
    write (1, "rr\n", 3);
}

void rev_rotate_a(t_list **list)
{
   	t_list	*temp;
	t_list	*prev;

	if (*list == NULL)
		return ;
	else
	{
		temp = (*list);
		while ((*list)->next != NULL)
		{
			prev = (*list);
			(*list) = (*list)->next;
		}
		prev->next = NULL;
		(*list) = (*list);
		(*list)->next = temp;
	}
    write (1, "rra\n", 4);
}

void rev_rotate_b(t_list **list)
{
	t_list	*temp;
	t_list	*prev;

	if (*list == NULL)
		return ;
	else
	{
		temp = (*list);
		while ((*list)->next != NULL)
		{
			prev = (*list);
			(*list) = (*list)->next;
		}
		prev->next = NULL;
		(*list) = (*list);
		(*list)->next = temp;
	}
    write (1, "rrb\n", 4);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	if (*list_a)
		ft_r_rr(list_a);
	if (*list_b)
		ft_r_rr(list_b);
	write (1, "rrr\n", 4);
}

void	ft_r_rr(t_list **list)
{
	t_list	*temp;
	t_list	*prev;

	temp = (*list);
	while ((*list)->next != NULL)
	{
		prev = (*list);
		(*list) = (*list)->next;
	}
	prev->next = NULL;
	(*list) = (*list);
	(*list)->next = temp;
}