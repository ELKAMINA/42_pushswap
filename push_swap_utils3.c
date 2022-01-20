#include "push_swap.h"

void sorting_three(t_list *head)
{
    int nb1;
    int nb2;
    int nb3;

    nb1 = head -> data;
    nb2 = head -> next -> data;
    nb3 = head -> next -> next -> data;

    printf("_____%d %d %d_______", nb1, nb2, nb3);
}
