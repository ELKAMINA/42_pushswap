#include "push_swap.h"

void swap_a(t_list  *start)
{
    t_list  *n1;
    t_list  *n2;
    t_list  *n3;
    t_list  *temp;

    n1 =  start;
    // Ici comme la fonction recoit double pointeur => https://stackoverflow.com/questions/14766683/pointing-dereference-inside-a-struct-error
    n2 =  n1 -> next;
    n3 = n2 -> next;
    temp = n1 -> previous;
    n1 -> next = n3;
    n1 -> previous = n2;
    n2 -> previous = temp;
    n2 -> next = n1;
    if (n3 != NULL)
        n3 -> previous = n1;
    start = n2;
    // https://stackoverflow.com/questions/33455329/swap-first-2-nodes-only-in-a-doubly-linked-list
    // while (start != NULL)
    // { 
    //     printf("%d\n", start -> data);
    //     start = start -> next;
    // }
}