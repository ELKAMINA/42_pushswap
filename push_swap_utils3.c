#include "push_swap.h"

int higher(t_list   **head)
{
    int min_int;
    int max;
    
    min_int = -32767;
    max = min_int;
    while ( *head != NULL)
    {
        if  (max < (*head)->data)
            max = (*head)->data;
        *head = (*head)->next;
    }
    return (max);
}

int lower(t_list   **head)
{
    int max_int;
    int min;
    
    max_int = 32767;
    min = max_int;
    while ( *head != NULL)
    {
        if  (min > (*head)->data)
            min = (*head)->data;
        *head = (*head)->next;
    }
    return (min);
}

void sorting_one(t_list **head)
{
    t_list *first;

    first = *head;
    if (first -> next == NULL)
        return ;
}

void sorting_two(t_list **head)
{
    t_list *first;
    t_list *second;

    first = *head;
    second = first->next;
    if (first->data > second->data)
        swap_a(head);
    else
        return ;
}

void sorting_three(t_list **head)
{
    int nb1;
    int nb2;
    int nb3;

    nb1 = (*head)->data;
    nb2 = (*head)->next->data;
    nb3 = (*head)->next->next->data;

    // printf("_____%d %d %d_______\n", nb1, nb2, nb3);
    if (nb1 > nb2 && nb2 < nb3 && nb3 > nb1)
        swap_a(head);
    else if (nb1 > nb2 && nb2 > nb3 && nb3 < nb1)
    {
        swap_a(head);
        rev_rotate_a(head);
    }
    else if (nb1 > nb2 && nb2 < nb3 && nb3 < nb1)
    {
        rotate_a(head);
    }
    else if (nb1 < nb2 && nb2 > nb3 && nb3 > nb1)
    {
        swap_a(head);
        rotate_a(head);
    }
    else if (nb1 < nb2 && nb2 > nb3 && nb3 < nb1)
    {
        rev_rotate_a(head);
        printf("_____%d %d %d_______\n", (*head)->data, (*head)->next->data, (*head)->next->next->data);
    }
    else
    {
        return ;
    }
}

void sorting_four(t_list **head_A, t_list **head_B)
//void sorting_four(t_list **head_A, t_list **head_B)
{
t_list *a;
t_list *b;
t_list *less;
int lst_size;
int index_lower;
int smallest;

less = (*head_A);
a = (*head_A);
b = (*head_B);
lst_size = ft_lstsize(a);
index_lower = 1;
smallest = lower(&a);
printf("(%d)\n", lst_size);
while(less-> data != smallest)
{
    index_lower++;
    less = less -> next;
}
//printf("(%d)\n", index_lower);
if (index_lower == lst_size)
{
   rev_rotate_a(head_A);
   push_b(head_B, head_A); 
}
else if (index_lower == lst_size - 1)
{
    rotate_a(head_A);
    rotate_a(head_A);
    push_b(head_B, head_A); 
}
else if (index_lower == lst_size - 2)
{
    swap_a(head_A);
    push_b(head_B, head_A); 
}
else
{
    push_b(head_B, head_A);
}
sorting_three(head_A);
// while((*head_A) != NULL)
// {
//     printf("(%d)", (*head_A)->data);
//     *head_A = (*head_A)->next;
// }
push_a(head_A, head_B);
}

void check_pos_and_push(t_list **head_A, t_list **head_B, int lst_size)
{
t_list *a;
t_list *less;
t_list *b;
int index_lower;
int smallest;

less = (*head_A);
a = (*head_A);
b = (*head_B);
index_lower = 1;
smallest = lower(&a);
//printf("%d", smallest);
//printf("(%d)\n", lst_size);
//printf("%d", (*head_B)->data);
while(less->data != smallest)
{
    index_lower++;
    less = less->next;
}
//printf("(%d)\n", index_lower);
if (index_lower == lst_size)
{
   rev_rotate_a(head_A);
   push_b(head_B, head_A); 
}
else if (index_lower == lst_size - 1)
{
    rev_rotate_a(head_A);
    rev_rotate_a(head_A);
    push_b(head_B, head_A); 
}
else if (index_lower == lst_size - 2)
{
    rotate_a(head_A);
    rotate_a(head_A);
    push_b(head_B, head_A);
}
else if (index_lower == 2)
{
    swap_a(head_A);
    push_b(head_B, head_A);
}
else
    push_b(head_B, head_A);
}

void sorting_five(t_list **head_A, t_list **head_B)
{
    int size;
    t_list *a;
    t_list *b;

    a = (*head_A);
    b = (*head_B);
    size = ft_lstsize(a);
    check_pos_and_push(head_A, head_B, size);
    sorting_four(head_A, head_B);
    push_a(head_A, head_B);
    //printf("%d", size);
    // printf("%d", (*head_B)->data);
}