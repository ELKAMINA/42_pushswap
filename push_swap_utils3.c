#include "push_swap.h"

void sorting_three(t_list **head)
{
    int nb1;
    int nb2;
    int nb3;

    nb1 = (*head)->data;
    nb2 = (*head)->next->data;
    nb3 = (*head)->next->next->data;

    //printf("_____%d %d %d_______\n", nb1, nb2, nb3);
    if (nb1 > nb2 && nb2 < nb3 && nb3 > nb1)
        swap_a(head);
    else if (nb1 > nb2 && nb2 > nb3 && nb3 < nb1)
    {
        swap_a(head);
        rev_rotate_a(head);
    }
    else if (nb1 > nb2 && nb2 < nb3 && nb3 < nb1)
        rotate_a(head);
    else if (nb1 < nb2 && nb2 > nb3 && nb3 > nb1)
    {
        swap_a(head);
        rotate_a(head);
    }
    else
        rev_rotate_a(head);
}
