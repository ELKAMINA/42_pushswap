#include "push_swap.h"

int calc_median(t_list **head)
{
    int max;
    int min;
    int median;
    t_list *start;
    t_list *start2;

    start = *head;
    start2 = *head;
    min = lower(&start);
    max = higher(&start2);
    median = (max - min)/2;
    return(median);
}

int update_pos(t_list **head, t_list *oneNode)
{
    int     size;
    int     i;
    int     pos;
    t_list *temp;

    temp = *head;
    i = 1;
    pos = 1;
    size = ft_lstsize(*head);
    while (temp->data != oneNode->data & i <= size)
    {
        pos++;
        temp = temp->next;
        i++;
    }
    return(pos);
}

int middle (t_list **head)
{
    int size;
    int mid;

    size = ft_lstsize(*head);
    mid = size/2;
    return (mid);
}

void sorting_under_hundred(t_list **head_A, t_list **head_B)
{
    int median;
    t_list  *bais;
    t_list  *copy;
    int pos;
    int i;
    int j;

    bais = *head_B;
    i = 1;
    j = 1;
    median = calc_median(head_A);
    copy = *head_A;
    pos = 1;
    while (copy)
    {
        if (copy->data < median)
        {
            pos = update_pos(head_A, copy);
            printf("{%d}", pos);
            if (pos >= middle(head_A)){
                while (i < pos)
                {
                    rotate_a(head_A);
                    i++;
                }
                push_b(head_B, head_A);
            }
            else 
            {
                while (i < pos)
                {
                    rev_rotate_a(head_A);
                    i++;
                }
                push_b(head_B, head_A);
            }
            copy = *head_A;
            i = 1;
        }
        else 
            copy = copy->next;
    }     
}



