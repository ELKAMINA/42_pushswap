/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:45:15 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 14:47:00 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

int	max_sort(t_list **head, int size)
{
	int	min_int;
	int	max;
	int	i;

	i = 0;
	min_int = -2147483648;
	max = min_int;
	while (i < size)
	{
		if (max < (*head)->sort)
			max = (*head)->sort;
		*head = (*head)->next;
		i++;
	}
	return (max);
}

int	min_moves(t_list **head)
{
	int		min;
	t_list	*copy;
	int		max_int;

	copy = *head;
	max_int = 2147483647;
	min = max_int;
	while (copy)
	{
		if (min > copy->total_moves)
			min = copy->total_moves;
		copy = copy->next;
	}
	return (min);
}
