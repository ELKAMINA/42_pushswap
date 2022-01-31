#include "push_swap.h"

int calc_median(t_list **head)
{
    int size;
    int index_median;


    size = ft_lstsize(*head);
    index_median = (size + 1)/2;
    return(index_median);
}

void sorting_under_hundred(t_list **head_A, t_list **head_B)
{
    int median;
    int size;
    int pos;

    median = calc_median(head_A);
    size = ft_lstsize(*head_A);
    pos = median;
    while (pos < size)
    {
        push_b(head_B, head_A);
        pos ++;
    }
}
