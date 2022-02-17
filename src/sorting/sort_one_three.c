/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:41:02 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 14:43:06 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sorting_one(t_list **head)
{
	t_list	*first;

	first = *head;
	if (first -> next == NULL)
		return ;
}

void	sorting_two(t_list **head)
{
	t_list	*first;
	t_list	*second;

	first = *head;
	second = first->next;
	if (first->data > second->data)
		swap_a(head);
	else
		return ;
}

void	sorting_three(t_list **head)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = (*head)->data;
	nb2 = (*head)->next->data;
	nb3 = (*head)->next->next->data;
	if (nb1 > nb2 && nb2 < nb3 && nb3 > nb1)
		swap_a(head);
	else if (nb1 > nb2 && nb2 > nb3 && nb3 < nb1)
	{
		swap_a(head);
		rev_rotate_a(head);
	}
	else if (nb1 > nb2 && nb2 < nb3 && nb3 < nb1)
		rotate_a(head);
	else if (nb1 < nb2 && nb2 > nb3 && nb3 > nb1)
	{
		swap_a(head);
		rotate_a(head);
	}
	else if (nb1 < nb2 && nb2 > nb3 && nb3 < nb1)
		rev_rotate_a(head);
	else
		return ;
}
