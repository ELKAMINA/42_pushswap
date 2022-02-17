/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:41:19 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 17:43:08 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../push_swap.h"

void	loop_rrr_b(t_list **head_A, t_list **head_B, int movesb)
{
	int	i;

	i = 1;
	while (i <= movesb)
	{
		rrr(head_A, head_B);
		i++;
	}
}

void	loop_rrr_a(t_list **head_A, t_list **head_B, int movesa)
{
	int	i;

	i = 1;
	while (i <= movesa)
	{
		rrr(head_A, head_B);
		i++;
	}
}

void	sec_loop_rrb(int discard, t_list **head_B)
{
	while (discard != 0)
	{
		rev_rotate_b(head_B);
		discard++;
	}
}

void	sec_loop_rra(int discard, t_list **head_A)
{
	while (discard != 0)
	{
		rev_rotate_a(head_A);
		discard--;
	}
}
