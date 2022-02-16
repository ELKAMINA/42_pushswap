#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

void	partitionning();

// Définition d'un maillon de la liste Doublement Chainée
typedef struct s_list
{
	int	   		    data;
	int				sort;
	char			boolean;
	int				posinA;
	int				pos;
	int				moves;
	int				index;
	int				total_moves;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

void fonction_swap(t_list  *start);
void	print_lst(t_list  *start);
long	ft_atol(const char *str);
t_list	*ft_lstnew(int	argument);
void	ft_lstadd_back(t_list **alst, t_list *node);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void 	swap_a(t_list  **head_A);
void 	swap_b(t_list  **head_B);
void	ft_lstadd_front(t_list **alst, t_list *node);
void 	push_a(t_list **a, t_list **b);
void 	push_b(t_list **a, t_list **b);
void 	ss(t_list **a, t_list **b);
void 	rotate_a(t_list **a);
void 	rotate_b(t_list **b);
void 	rr(t_list **a, t_list **b);
void 	rrr(t_list **a, t_list **b);
void	ft_r_rr(t_list **list);
void 	rev_rotate_a(t_list **a);
void 	rev_rotate_b(t_list **b);
void 	sorting_two(t_list **head_A);
void 	sorting_three(t_list **head_A);
void 	sorting_four(t_list **head_A, t_list **head_B);
void 	sorting_five(t_list **head_A, t_list **head_B);
void 	sorting_above_five(t_list **head_A, t_list **head_B);
int		higher(t_list   **head);
int 	lower(t_list   **head);
int 	check_is_sorted(t_list **head);
int 	calc_median(t_list **head);
int 	middle (int size);
void 	circularing_LL(t_list **A);
void 	node_to_sendtoB(t_list **A, t_list **head_B, int size);
int 	max_sort(t_list   **head_A, int size);
void 	cost_calculation_pushtoB(t_list **head_A, t_list **head_B, int size);
void 	cost_calculation_toheadList(t_list **head_B);
int 	check_pos_in_A(t_list **A, t_list *oneNode);
void 	get_index(t_list **head);
int 	min_moves_toHead(t_list   **head, int size);
int 	min_moves(t_list   **head);
void 	pushing_to_A(t_list **A, t_list **B);
void 	get_cost_to_positionNodeB_inA(t_list **headA, t_list **headB);
void 	pushing_toheadListB(t_list **headB, int index);
void 	pushing_toheadListA(t_list **headA, int index, int size);
void 	last_sort (t_list **headA);
void 	decircularing(t_list **A, int size);
void 	get_moves_to_zero(t_list **headA, t_list **headB);
void 	ft_optimise(t_list **head_A, t_list **head_B, t_list *copyA, t_list *copyB);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
size_t	ft_strlen(char *str);

#endif