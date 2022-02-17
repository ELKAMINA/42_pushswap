/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:08:37 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 18:09:01 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*ft_lstnew(int argument)
{
	t_list	*new;

	new = malloc(sizeof (t_list));
	if (new == NULL)
		return (NULL);
	new -> data = argument;
	new -> next = NULL;
	new -> previous = NULL;
	new->sort = 1;
	new->boolean = 'F';
	new->posina = 1;
	new->pos = 1;
	new->moves = 0;
	return (new);
}
