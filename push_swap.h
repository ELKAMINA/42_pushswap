/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:57:28 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 18:15:26 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	int				sort;
	char			boolean;
	int				posina;
	int				pos;
	int				moves;
	int				index;
	int				total_moves;
	struct s_list	*previous;
	struct s_list	*next;
}		t_list;

long	ft_atol(const char *str);
t_list	*ft_lstnew(int argument);
void	ft_lstadd_back(t_list **alst, t_list *node);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
int		check_dup(char *argv[], int n);
int		check_char(char *argv[]);
int		check_sp(char *argv[]);
int		check_dsi(char *argv[]);
void	swap_a(t_list **head_A);
void	swap_b(t_list **head_B);
void	ft_lstadd_front(t_list **alst, t_list *node);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
void	ft_r_rr(t_list **list);
void	rev_rotate_a(t_list **a);
void	rev_rotate_b(t_list **b);
void	sorting_two(t_list **head_A);
void	sorting_three(t_list **head_A);
void	sorting_four(t_list **head_A, t_list **head_B);
void	sorting_five(t_list **head_A, t_list **head_B);
void	pos_for_check(t_list **head_A, t_list **head_B, int ind);
void	pos(t_list **head_A, t_list **head_B, int ind);
void	incr_sort(int sizea, t_list **head_A);
void	looping_r_pu(int index, t_list **headA, t_list **headB);
void	looping_rr_pu(int index, t_list **headA, t_list **headB);
void	loop_up_moves(t_list *copy, int ind);
void	loop_up_moves_b(t_list *copy, int ind, int size);
void	sorting_above_five(t_list **head_A, t_list **head_B);
int		higher(t_list **head);
int		lower(t_list **head);
int		check_is_sorted(t_list **head);
int		calc_median(t_list **head);
int		middle(int size);
void	circularing(t_list **a);
void	node_to_sendtob(t_list **a, t_list **head_B, int size);
int		max_sort(t_list **a, int size);
void	cost_calculation_pushtob(t_list **a, t_list **b, int size);
void	cost_calculation_toheadlist(t_list **b);
int		check_pos_in_a(t_list **a, t_list *oneNode);
void	get_index(t_list **head);
int		min_moves_toHead(t_list **head, int size);
int		min_moves(t_list **head);
void	pushing_to_a(t_list **a, t_list **b);
void	get_cost_to_pos_nodeb_ina(t_list **headA, t_list **headB);
void	pushing_toheadlistb(t_list **headB, int index);
void	pushing_toheadlista(t_list **headA, int index, int size);
void	last_sort(t_list **headA);
void	decircularing(t_list **A, int size);
void	get_moves_to_zero(t_list **headA, t_list **headB);
void	opti(t_list **a, t_list **b, t_list *ca, t_list *cb);
void	loop_rr_b(t_list **head_A, t_list **head_B, int movesb);
void	loop_rr_a(t_list **head_A, t_list **head_B, int movesa);
void	sec_loop_rb(int discard, t_list **head_B);
void	sec_loop_ra(int discard, t_list **head_A);
void	loop_rrr_b(t_list **head_A, t_list **head_B, int movesb);
void	loop_rrr_a(t_list **head_A, t_list **head_B, int movesa);
void	sec_loop_rrb(int discard, t_list **head_B);
void	sec_loop_rra(int discard, t_list **head_A);
void	case_one(t_list **a, t_list **b, t_list *ca, t_list *cb);
void	case_two(t_list **a, t_list **b, t_list *ca, t_list *cb);
void	headab(t_list **head_A, t_list **head_B, t_list *copyA, t_list *copyB);
void	loop_to_pushb(int ind, t_list **headB);
void	loop_to_rrb(int ind, t_list **headB, int size);
void	loop_to_pusha(int ind, t_list **headA);
void	loop_to_rra(int ind, t_list **headA, int size);
void	loop_nodetosend(t_list *current, t_list *copy, t_list *moving);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
size_t	ft_strlen(char *str);

#endif
