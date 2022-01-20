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
	int			    data;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

long	ft_atol(const char *str);
t_list	*ft_lstnew(int	argument);
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void 	swap_a(t_list  *head_A);
void 	swap_b(t_list  *head_B);
void	ft_lstadd_front(t_list **alst, t_list *new);
void 	push_a(t_list **a, t_list **b);
void 	push_b(t_list **a, t_list **b);
void 	ss(t_list *a, t_list *b);
void 	rotate_a(t_list **a);
void 	rotate_b(t_list **b);
void 	rotate_rr(t_list **a);
void 	rev_rotate_a(t_list **a);
void 	rev_rotate_b(t_list **b);
void 	sorting_three(t_list *head_A);

#endif