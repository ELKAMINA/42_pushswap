#include "../../push_swap.h"

void last_sort (t_list **headA)
{
    t_list *copy;
    t_list *copy2;
    int min;

    get_index(headA);
    copy = *headA;
    copy2 = *headA;
    min = lower(&copy2);
    while (copy->data != min)
        copy = copy->next;
    pushing_toheadListA(headA, copy->index, ft_lstsize(*headA));
}

void 	sorting_above_five(t_list **head_A, t_list **head_B)
{
    t_list *copy;
    t_list *moving;
    t_list *current;
    int sizeA;
    int i;

    i = 0;
    copy = *head_A;
    sizeA = ft_lstsize(*head_A);
    circularing_LL(head_A);
    while(i < sizeA)
    {
        moving = copy;
        current = copy->next;
        while (current != copy)
        {
            if (current->data > moving->data)
            {
                moving = current;
                copy->sort += 1;
            }
            current = current->next;
        }
       // printf("MAX SORTED DATA------> %d, MAX SORTED : %d\n", current->data, current->sort);
        copy = copy->next;
        i++;
    }
    node_to_sendtoB(head_A, head_B, sizeA);
    while (*head_B)
        pushing_to_A(head_A, head_B);
    last_sort(head_A);
}