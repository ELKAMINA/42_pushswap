/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:09:59 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 12:21:47 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	last_sort(t_list **headA)
{
	t_list		*copy;
	t_list		*copy2;
	int			min;

	get_index(headA);
	copy = *headA;
	copy2 = *headA;
	min = lower(&copy2);
	while (copy->data != min)
		copy = copy->next;
	pushing_toheadListA(headA, copy->index, ft_lstsize(*headA));
}

void	incr_sort(int sizea, t_list **head_A)
{
	t_list		*copy;
	t_list		*moving;
	t_list		*current;
	int			i;

	i = 0;
	copy = *head_A;
	while (i < sizea)
	{
		moving = copy;
		current = copy->next;
		while (current != copy)
		{
			if (current->data > moving->data)
			{
				moving = current;
				copy->sort += 1;
			}
			current = current->next;
		}
		copy = copy->next;
		i++;
	}
}

void	sorting_above_five(t_list **head_A, t_list **head_B)
{
	int			sizea;

	sizea = ft_lstsize(*head_A);
	circularing_LL(head_A);
	incr_sort(sizea, head_A);
	node_to_sendtoB(head_A, head_B, sizea);
	while (*head_B)
		pushing_to_A(head_A, head_B);
	last_sort(head_A);
}
