#include "../../../push_swap.h"

int update_pos(t_list **head, t_list *oneNode, int size)
{
    int     i;
    int     pos;
    t_list *temp;

    temp = *head;
    i = 1;
    pos = 1;
    while ((temp->data != oneNode->data) & (i <= size))
    {
        pos++;
        temp = temp->next;
        i++;
    }
    return(pos);
}

int check_pos_in_A(t_list **A, t_list *oneNode)
{
    t_list *copy;
    t_list *copyformin;
    int lowest;
    int i;

    copy = *A;
    copyformin = *A;
    lowest = lower(&copyformin);
    i = 1;
    get_index(A);
    while (copy && copy->next)
    {
        if (copy->data < oneNode->data && copy->next->data > oneNode->data)
            return (i);
        else if (copy->data == lowest && oneNode->data < copy->data)
            return (copy->index - 1);
        copy = copy->next;
        i++;
    }
    if (copy->data == lowest && oneNode->data < copy->data)
            return (copy->index - 1);
    return (0);
}