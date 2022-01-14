#include "push_swap.h"

void swap_a(t_list  *head_A)
{
t_list  *ptr1;
t_list  *ptr2;

ptr1 =  head_A;
ptr2 =  head_A -> next;

ptr2 -> next = ptr2 -> previous;
ptr2 -> previous = NULL;
ptr1 -> previous = ptr2;
ptr1 -> next -> next = NULL;
}