#include "../../push_swap.h"

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

void get_index(t_list **head)
{
    t_list *copy;
    int    i;

    copy = *head;
    i = 1;
    while(copy)
    {
        copy->index = i;
        copy = copy->next;
        i++;
    }
}

int middle (int size)
{
    int mid;

    if (size % 2 != 0)
    {
        mid = (size + 1) / 2;
    }
    else 
        mid = size / 2;
    return (mid);
}