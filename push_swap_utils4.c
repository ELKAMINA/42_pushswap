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
    // int size;
    int pos;
    int i;

    bais = *head_B;
    i = 1;
    median = calc_median(head_A);
    copy = NULL;
    // printf("%d", copy->data);
    pos = 1;
    while (copy)
    {
        //copy = *head_A;
        //printf("[%d]\n", copy->data);
        //printf("[%d]\n", (*head_A)->next->data);
        if (copy->data < median)
        {
            pos = update_pos(head_A, copy);
            //printf("{%d}", pos);
            //printf("{%d}", middle(head_A));
            if (pos >= middle(head_A)){
                while (i < pos)
                {
                    rotate_a(head_A);
                    i++;
                }
                push_b(head_B, head_A);
                //copy = *head_A;
            }
            else 
            {
                while (i < pos)
                {
                    rev_rotate_a(head_A);
                    i++;
                }
                push_b(head_B, head_A);
                //copy = *head_A;
            }
        }
        // copy = *head_A;
        // pos = 1;
        // else 
        //     copy = copy->next;
        // copy = *head_A;
        // pos = 1;
        copy = copy->next;
    }
}

