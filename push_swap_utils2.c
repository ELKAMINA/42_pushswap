#include "push_swap.h"

void rotate_a(t_list **a)
{
    t_list  *newNode;

    newNode = *a;
    if (!*a || !(*a)->next)
        return;
    while (newNode -> next -> next)
        newNode = newNode -> next;
    (*a) -> previous = newNode -> next -> next;
    newNode -> next -> next = (*a);
    (*a) = (*a) -> next;
    (*a) -> previous = NULL;
    newNode -> next -> next -> next =  NULL;
    write(1, "ra\n", 3);
}

void rotate_b(t_list **b)
{
    t_list  *newNode;

    newNode = *b;
    if (!*b || !(*b)->next)
        return;
    while (newNode -> next -> next)
        newNode = newNode -> next;
    newNode -> next -> next = newNode-> previous;
    newNode -> previous -> previous = newNode-> next -> next;
    newNode -> next -> next -> next = NULL;
    newNode -> previous = NULL;
    *b = newNode;
    write(1, "rb\n", 3);
}

void rr(t_list **a, t_list **b)
{
    rotate_a(&*a);
    rotate_b(&*b);
    write (1, "rr\n", 3);
}

void rev_rotate_a(t_list **a)
{
    t_list  *newNode;

    newNode = *a;
    if (!*a || !(*a)->next)
        return ;
    while (newNode -> next ->next)
        newNode = newNode -> next;
    newNode ->next -> next = *a;
    (*a)->previous = newNode->next->next;
    (*a) = newNode -> next;
    newNode -> next = NULL;
    (*a)->previous = NULL; 
    write (1, "rra\n", 4);
}

void rev_rotate_b(t_list **b)
{
    t_list  *newNode;

    newNode = *b;
    if (!*b || !(*b)->next)
        return ;
    while (newNode -> next ->next)
        newNode = newNode -> next;
    newNode ->next -> next = *b;
    (*b)->previous = newNode->next->next;
    (*b) = newNode -> next;
    newNode -> next = NULL;
    (*b)->previous = NULL; 
    write (1, "rrb\n", 4);
}