/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cir_decir_dll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:55:05 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 15:04:34 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	decircularing(t_list **A, int size)
{
	t_list	*copy;
	int		i;

	i = 0;
	copy = *A;
	copy->previous = NULL;
	while (i < size - 1)
	{
		copy = copy->next;
		i++;
	}
	copy->next = NULL;
}

void	circularing(t_list **a)
{
	t_list	*copy;
	t_list	*head;

	copy = *a;
	head = *a;
	while (copy->next != NULL)
		copy = copy->next;
	copy->next = head;
	head->previous = copy;
}
