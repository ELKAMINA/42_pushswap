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

// Définition de la DClist qui va contenir head and tail
// typedef struct DC_List
// {
// 	int			    *length;
// 	struct DC_List	*head;
// 	struct DC_List	*tail;
// }*DC_List;

long	ft_atol(const char *str);
t_list	*ft_lstnew(int	argument);
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void 	swap_a(t_list  *head_A);

#endif