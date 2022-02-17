/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revRotate_and_rrr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:44:00 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 17:44:38 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rev_rotate_a(t_list **list)
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

void	rev_rotate_b(t_list **list)
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
