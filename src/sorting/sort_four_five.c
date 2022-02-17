/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:25:55 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 14:28:15 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	check_is_sorted(t_list **head)
{
	t_list	*temp;

	temp = *head;
	while (temp && temp->next)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	pos(t_list **head_A, t_list **head_B, int ind)
{
	if (ind == ft_lstsize(*head_A))
	{
		rev_rotate_a(head_A);
		push_b(head_B, head_A);
	}
	else if (ind == ft_lstsize(*head_A) - 1)
	{
		rotate_a(head_A);
		rotate_a(head_A);
		push_b(head_B, head_A);
	}
	else if (ind == ft_lstsize(*head_A) - 2)
	{
		swap_a(head_A);
		push_b(head_B, head_A);
	}
	else
		push_b(head_B, head_A);
}

void	pos_for_check(t_list **head_A, t_list **head_B, int ind)
{
	if (ind == ft_lstsize(*head_A))
	{
		rev_rotate_a(head_A);
		push_b(head_B, head_A);
	}
	else if (ind == ft_lstsize(*head_A) - 1)
	{
		rev_rotate_a(head_A);
		rev_rotate_a(head_A);
		push_b(head_B, head_A);
	}
	else if (ind == ft_lstsize(*head_A) - 2)
	{
		rotate_a(head_A);
		rotate_a(head_A);
		push_b(head_B, head_A);
	}
	else if (ind == 2)
	{
		swap_a(head_A);
		push_b(head_B, head_A);
	}
	else
		push_b(head_B, head_A);
}

void	sorting_four(t_list **head_A, t_list **head_B)
{
	t_list		*less;
	t_list		*a;
	int			ind;
	int			sm;

	less = (*head_A);
	a = (*head_A);
	ind = 1;
	sm = lower(&a);
	if (check_is_sorted(head_A) == 1)
		return ;
	else
	{
		while (less->data != sm)
		{
			ind++;
			less = less -> next;
		}
		pos(head_A, head_B, ind);
		sorting_three(head_A);
		push_a(head_A, head_B);
	}
}
