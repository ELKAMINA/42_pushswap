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

// void rotate_b(t_list **b)
// {
//     t_list  *newNode;

//     newNode = *b;
//     if (!*b || !(*b)->next)
//         return;
//     while (newNode -> next -> next)
//         newNode = newNode -> next;
//     newNode -> next -> next = newNode-> previous;
//     newNode -> previous -> previous = newNode-> next -> next;
//     newNode -> next -> next -> next = NULL;
//     newNode -> previous = NULL;
//     *b = newNode;
//     write(1, "rb\n", 3);
// }

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


void rr(t_list **a, t_list **b)
{
    rotate_a(&*a);
    rotate_b(&*b);
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