/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_update_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:47:15 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 14:50:52 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

int	update_pos(t_list **head, t_list *oneNode, int size)
{
	int		i;
	int		pos;
	t_list	*temp;

	temp = *head;
	i = 1;
	pos = 1;
	while ((temp->data != oneNode->data) & (i <= size))
	{
		pos++;
		temp = temp->next;
		i++;
	}
	return (pos);
}

int	check_pos_in_a(t_list **a, t_list *one_node)
{
	t_list	*copy;
	t_list	*copyformin;
	int		lowest;
	int		i;

	copy = *a;
	copyformin = *a;
	lowest = lower(&copyformin);
	i = 1;
	get_index(a);
	while (copy && copy->next)
	{
		if (copy->data < one_node->data && copy->next->data > one_node->data)
			return (i);
		else if (copy->data == lowest && one_node->data < copy->data)
			return (copy->index - 1);
		copy = copy->next;
		i++;
	}
	if (copy->data == lowest && one_node->data < copy->data)
		return (copy->index - 1);
	return (0);
}
