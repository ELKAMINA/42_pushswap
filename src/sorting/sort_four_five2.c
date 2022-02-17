/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:28:29 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 14:28:43 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	check_pos_and_push(t_list **head_A, t_list **head_B)
{
	t_list	*a;
	t_list	*less;
	int		ind;
	int		sm;

	less = (*head_A);
	a = (*head_A);
	ind = 1;
	sm = lower(&a);
	while (less->data != sm)
	{
		ind++;
		less = less->next;
	}
	pos_for_check(head_A, head_B, ind);
}

void	sorting_five(t_list **head_A, t_list **head_B)
{
	if (check_is_sorted(head_A) == 1)
		return ;
	else
	{
		check_pos_and_push(head_A, head_B);
		sorting_four(head_A, head_B);
		push_a(head_A, head_B);
	}
}
