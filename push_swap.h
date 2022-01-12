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
	int			    *data;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

// Définition de la DClist qui va contenir head and tail
typedef struct DC_List
{
	int			    *length;
	struct DC_List	*head;
	struct DC_List	*tail;
}*DC_List;
long	ft_atol(const char *str);

#endif