/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:20:40 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 17:20:53 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	loop_to_pushb(int ind, t_list **headB)
{
	int	i;

	i = 0;
	while (i < ind - 1)
	{
		rotate_b(headB);
		i++;
	}
}

void	loop_to_rrb(int ind, t_list **headB, int size)
{
	int	i;

	i = ind;
	while (i <= size)
	{
		rev_rotate_b(headB);
		i++;
	}
}

void	loop_to_pusha(int ind, t_list **headA)
{
	int	i;

	i = 0;
	while (i < ind - 1)
	{
		rotate_a(headA);
		i++;
	}
}

void	loop_to_rra(int ind, t_list **headA, int size)
{
	int	i;

	i = ind;
	while (i <= size)
	{
		rev_rotate_a(headA);
		i++;
	}
}
