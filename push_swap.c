#include <stdio.h>
#include "push_swap.h"

// int	ft_intlen(int *tab)
// {
//     int  i;

//     i = 0;
// 	while (tab[i])
//         i++;
//     //size_t len_ar;

//     //size_arr = sizeof(tab);
//     //printf("sizeof tab %d", size_arr);
//     //len_ar = sizeof(tab) / sizeof(tab[0]);
//     printf("sizeof tab %d", i);
//     return (i);
// }

// void	ft_swap(int	*a, int	*b)
// {
// 	int	eph;

// 	eph = 0;
// 	eph = *a;
// 	*a = *b;
// 	*b = eph;
// }

// void    partitionning(int start, int   *tab)
// {
//     int ind_beg;
//     int ind_end;

//     ind_beg = 0;
//     //printf(" je suis la length %zu", ft_intlen(tab));
//     // for (int i = 0; i < 10 ; i++)
//     // {
//     //     printf("%d\n", tab[i]);
//     // }
//     ind_end = ft_intlen(tab) - 1;
//     while (ind_beg < ind_end)
//     {
//         while (tab[++ind_beg] <= tab[0])
//             printf("%d", ind_beg);
//         while (tab[++ind_end] >= tab[0])en 
//             printf("%d", ind_end);
//         if (tab[ind_beg] < tab[ind_end])
//             ft_swap(&tab[ind_beg], &tab[ind_end]);
//     }
//     if (tab[ind_beg] < tab[ind_end])
//         ft_swap(&start, &tab[ind_end]);
// }

// /* Given a reference (pointer to pointer) to the head of a list
//    and an int, inserts a new node on the front of the list. */
// void push(struct Node** head_ref, int new_data)
// {
//     /* 1. allocate node */
//     struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

//     /* 2. put in the data  */
//     new_node->data = new_data;

//     /* 3. Make next of new node as head and previous as NULL */
//     new_node->next = (*head_ref);
//     new_node->prev = NULL;

//     /* 4. change prev of head node to new node */
//     if ((*head_ref) != NULL)
//         (*head_ref)->prev = new_node;

//     /* 5. move the head to point to the new node */
//     (*head_ref) = new_node;
// }

long	ft_atol(const char *str)
{
	long	i;
	long	neg;
	long	r;

	i = 0;
	neg = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i ++;
		if (r * neg > 2147483647)
			return (-1);
		if (r * neg < -2147483648)
			return (0);
	}
	return (r * neg);
}

int counting_int(char *argv[])
{
int i;

i = 0;
while (argv[i])
    i++;
return (i);
}


int main (int   argc, char  *argv[])
{
	int i;
	int n;
	// int argument;
	t_list *new_node;
	t_list *p;
	t_list *head;

	if (argc < 2)
		return 0;
	n = counting_int(argv) - 1;
	// argument = ft_atol(argv[4]);
	new_node = ft_lstnew((int)ft_atol(argv[1]));
	new_node = (t_list *)malloc(sizeof(new_node));
	new_node->data = (int *)ft_atol(argv[1]);
	new_node->next = NULL;
	new_node->previous = NULL;
	head = new_node;
	p = new_node;
	i = 2;
	while (i <= n)
	{
		new_node = (t_list*)malloc(sizeof(new_node));
		new_node->data = (int *)ft_atol(argv[i]);
		new_node->next = NULL;
		new_node->previous = p;
		p->next = new_node;
		p = p->next;
		i++;
	}
	p->next = head;
	head->previous = p;
	while(p!=NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	return 0 ;
}
