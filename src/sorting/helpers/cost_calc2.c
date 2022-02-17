/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:51:37 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 16:00:26 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	loop_up_moves(t_list *copy, int ind)
{
	int	i;

	i = 0;
	while (i < ind - 1)
	{
		copy->moves += 1;
		i++;
	}
}

void	loop_up_moves_b(t_list *copy, int ind, int size)
{
	int	i;

	i = ind;
	while (i <= size)
	{
		copy->moves += 1;
		i++;
	}
}

void	cost_calculation_toheadlist(t_list **head)
{
	t_list	*copy;
	int		size;

	copy = *head;
	size = ft_lstsize(*head);
	get_index(head);
	while (copy)
	{
		if (copy->index == 1)
			copy->moves = 0;
		else if (copy->index == 2)
			copy->moves = 1;
		else if (copy->index <= middle(size))
			loop_up_moves(copy, copy->index);
		else
			loop_up_moves_b(copy, copy->index, size);
		copy = copy->next;
	}
}

void	get_moves_to_zero(t_list **heada, t_list **headb)
{
	t_list	*copya;
	t_list	*copyb;

	copya = *heada;
	copyb = *headb;
	while (copya)
	{
		copya->moves = 0;
		copya->total_moves = 0;
		copya = copya->next;
	}
	while (copyb)
	{
		copyb->moves = 0;
		copyb->total_moves = 0;
		copyb = copyb->next;
	}
}
