/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:39:36 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 17:41:08 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../push_swap.h"

void	loop_rr_b(t_list **head_A, t_list **head_B, int movesb)
{
	int	i;

	i = 1;
	while (i <= movesb)
	{
		rr(head_A, head_B);
		i++;
	}
}

void	loop_rr_a(t_list **head_A, t_list **head_B, int movesa)
{
	int	i;

	i = 1;
	while (i <= movesa)
	{
		rr(head_A, head_B);
		i++;
	}
}

void	sec_loop_rb(int discard, t_list **head_B)
{
	while (discard != 0)
	{
		rotate_b(head_B);
		discard++;
	}
}

void	sec_loop_ra(int discard, t_list **head_A)
{
	while (discard != 0)
	{
		rotate_a(head_A);
		discard--;
	}
}
