/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:45:15 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 17:46:14 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_a(t_list **list)
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

void	rotate_b(t_list **list)
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

void	rr(t_list **list_a, t_list **list_b)
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
