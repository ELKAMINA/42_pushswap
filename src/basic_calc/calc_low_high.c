#include "../../push_swap.h"

int higher(t_list   **head)
{
    int min_int;
    int max;
    
    min_int = -2147483648;
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
    
    max_int = 2147483647;
    min = max_int;
    while ( *head != NULL)
    {
        if  (min > (*head)->data)
            min = (*head)->data;
        *head = (*head)->next;
    }
    return (min);
}