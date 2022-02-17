/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:49:09 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 15:50:16 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	sw_pu(t_list **heada, t_list **headb)
{
	swap_a(heada);
	push_b(headb, heada);
}

void	looping_r_pu(int index, t_list **heada, t_list **headb)
{
	int	i;

	i = 1;
	while (i < index)
	{
		rotate_a(heada);
		i++;
	}
	push_b(headb, heada);
}

void	looping_rr_pu(int index, t_list **heada, t_list **headb)
{
	int	i;

	i = index;
	while (i <= ft_lstsize(*heada))
	{
		rev_rotate_a(heada);
		i++;
	}
	push_b(headb, heada);
}

void	cost_calculation_pushtob(t_list **head_a, t_list **head_b, int size)
{
	t_list	*copy;

	decircularing(head_a, size);
	copy = *head_a;
	get_index(head_a);
	while (copy)
	{
		if (copy->boolean == 'F')
		{
			if (copy->index == 1)
				push_b(head_b, head_a);
			else if (copy->index == 2)
				sw_pu(head_a, head_b);
			else if (copy->index <= middle(ft_lstsize(*head_a)))
				looping_r_pu(copy->index, head_a, head_b);
			else
				looping_rr_pu(copy->index, head_a, head_b);
			copy = *head_a;
			get_index(head_a);
		}
		else
			copy = copy->next;
	}
}

void	get_cost_to_pos_nodeb_ina(t_list **heada, t_list **headb)
{
	t_list	*copya;
	t_list	*copyb;

	get_index(heada);
	get_index(headb);
	cost_calculation_toheadlist(headb);
	cost_calculation_toheadlist(heada);
	copya = *heada;
	copyb = *headb;
	while (copyb)
	{
		copyb->posina = check_pos_in_a(heada, copyb) + 1;
		while (copyb->posina != copya->index)
			copya = copya->next;
		copyb->total_moves = copya->moves + copyb->moves + 1;
		copyb = copyb->next;
		copya = *heada;
	}
}
