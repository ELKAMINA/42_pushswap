/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:14:47 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 17:20:22 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	pushing_toheadlistb(t_list **headB, int index)
{
	t_list	*copy;
	int		size;

	copy = *headB;
	size = ft_lstsize(*headB);
	get_index(headB);
	while (copy->index != index)
		copy = copy->next;
	if (copy->index == 1)
		return ;
	else if (copy->index == 2)
		swap_b(headB);
	else if (copy->index <= middle(size))
		loop_to_pushb(copy->index, headB);
	else
		loop_to_rrb(copy->index, headB, size);
}

void	pushing_toheadlista(t_list **headA, int index, int size)
{
	t_list	*copy;

	copy = *headA;
	get_index(headA);
	while (copy->index != index)
		copy = copy->next;
	if (copy->index == 1)
		return ;
	else if (copy->index == 2)
		rotate_a(headA);
	else if (copy->index <= middle(size))
		loop_to_pusha(copy->index, headA);
	else
		loop_to_rra(copy->index, headA, size);
}

void	loop_nodetosend(t_list *current, t_list *copy, t_list *moving)
{
	while (current != copy)
	{
		if (current->data > moving->data)
		{
			moving = current;
			moving->boolean = 'T';
		}
		current = current->next;
	}
}

void	node_to_sendtob(t_list **a, t_list **b, int size)
{
	t_list	*copy;
	int		sort_max;
	t_list	*moving;
	t_list	*current;

	copy = *a;
	sort_max = max_sort(a, size);
	while (copy->sort != sort_max)
		copy = copy->next;
	copy->boolean = 'T';
	moving = copy;
	current = copy->next;
	loop_nodetosend(current, copy, moving);
	cost_calculation_pushtob(a, b, size);
}

void	pushing_to_a(t_list **head_A, t_list **head_B)
{
	t_list	*copya;
	t_list	*copyb;
	t_list	*sec_copyb;

	copya = *head_A;
	copyb = *head_B;
	sec_copyb = *head_B;
	get_moves_to_zero(head_A, head_B);
	get_cost_to_pos_nodeb_ina(head_A, head_B);
	while (copyb->total_moves != min_moves(&sec_copyb))
		copyb = copyb->next;
	copyb->posina = check_pos_in_a(head_A, copyb) + 1;
	get_index(head_A);
	while (copya->index != copyb->posina)
		copya = copya->next;
	opti(head_A, head_B, copya, copyb);
	push_a(head_A, head_B);
}
