/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimising.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:52:07 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 16:55:17 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	case_one(t_list **head_A, t_list **head_B, t_list *copyA, t_list *copyB)
{
	int		discard;
	t_list	*same1;
	t_list	*same2;

	same1 = *head_A;
	same2 = *head_B;
	while (same1->data != copyA->data)
		same1 = same1->next;
	while (same2->data != copyB->data)
		same2 = same2->next;
	discard = same1->moves - same2->moves;
	if (discard == 0)
		loop_rr_b(head_A, head_B, copyB->moves);
	else if (discard < 0)
	{
		loop_rr_a(head_A, head_B, copyA->moves);
		sec_loop_rb(discard, head_B);
	}
	else
	{
		loop_rr_b(head_A, head_B, copyB->moves);
		sec_loop_ra(discard, head_A);
	}
}

void	case_two(t_list **head_A, t_list **head_B, t_list *copyA, t_list *copyB)
{
	int		discard;
	t_list	*same1;
	t_list	*same2;

	same1 = *head_A;
	same2 = *head_B;
	while (same1->data != copyA->data)
		same1 = same1->next;
	while (same2->data != copyB->data)
		same2 = same2->next;
	discard = same1->moves - same2->moves;
	if (discard == 0)
		loop_rrr_b(head_A, head_B, copyB->moves);
	else if (discard < 0)
	{
		loop_rrr_a(head_A, head_B, copyA->moves);
		sec_loop_rrb(discard, head_B);
	}
	else
	{
		loop_rrr_b(head_A, head_B, copyB->moves);
		sec_loop_rra(discard, head_A);
	}
}

void	headab(t_list **head_A, t_list **head_B, t_list *copyA, t_list *copyB)
{
	pushing_toheadlistb(head_B, copyB->index);
	pushing_toheadlista(head_A, copyA->index, ft_lstsize(*head_A));
}

void	opti(t_list **head_A, t_list **head_B, t_list *copyA, t_list *copyB)
{
	t_list	*same1;
	t_list	*same2;

	same1 = *head_A;
	same2 = *head_B;
	while (same1->data != copyA->data)
		same1 = same1->next;
	while (same2->data != copyB->data)
		same2 = same2->next;
	if (same1->moves == 0 && same2->moves > 0)
		pushing_toheadlistb(head_B, same2->index);
	else if (same2->moves == 0 && same1->moves > 0)
		pushing_toheadlista(head_A, same1->index, ft_lstsize(*head_A));
	else if (same1->index <= middle(ft_lstsize(*head_A))
		&& same2->index <= middle(ft_lstsize(*head_B)))
		case_one(head_A, head_B, copyA, copyB);
	else if (same1->index > middle(ft_lstsize(*head_A))
		&& same2->index > middle(ft_lstsize(*head_B)))
		case_two(head_A, head_B, copyA, copyB);
	else
		headab(head_A, head_B, copyA, copyB);
}
