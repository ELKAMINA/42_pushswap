#include "../../push_swap.h"

int check_is_sorted(t_list **head)
{
    t_list *temp;

    temp = *head;
    while (temp && temp->next)
    {
        if (temp->data < temp->next->data)
            temp = temp->next;
        else
            return (0);
    }
    return (1);
}

void sorting_four(t_list **head_A, t_list **head_B)
{
t_list *a;
t_list *less;
int lst_size;
int index_lower;
int smallest;

less = (*head_A);
a = (*head_A);
lst_size = ft_lstsize(a);
index_lower = 1;
smallest = lower(&a);
if (check_is_sorted(head_A) == 1)
    return ;
else
    {
        while(less-> data != smallest)
        {
            index_lower++;
            less = less -> next;
        }
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
        push_a(head_A, head_B);
    }
}

void check_pos_and_push(t_list **head_A, t_list **head_B, int lst_size)
{
t_list *a;
t_list *less;
int index_lower;
int smallest;

less = (*head_A);
a = (*head_A);
index_lower = 1;
smallest = lower(&a);
while(less->data != smallest)
{
    index_lower++;
    less = less->next;
}
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

    a = (*head_A);
    size = ft_lstsize(a);
    if (check_is_sorted(head_A) == 1)
        return ;
    else
    {
        check_pos_and_push(head_A, head_B, size);
        sorting_four(head_A, head_B);
        push_a(head_A, head_B);
    }
}