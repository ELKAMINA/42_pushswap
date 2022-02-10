#include "push_swap.h"

void swap_a(t_list  **start)
{
    t_list  *n1;
    t_list  *n2;
    t_list  *n3;
    t_list  *temp;


    n1 =  *start;
    if  (n1 == NULL)
        return ;
    n2 =  n1 -> next;
    if  (n2 == NULL)
        return ;
    n3 = n2 -> next;
    temp = n1 -> previous;
    n1 -> next = n3;
    n1 -> previous = n2;
    n2 -> previous = temp;
    n2 -> next = n1;
    if (n3 != NULL)
        n3 -> previous = n1;
    *start = n2;
    write (1, "sa\n", 3);
}

void swap_b(t_list  **start)
{
    t_list  *n1;
    t_list  *n2;
    t_list  *n3;
    t_list  *temp;

    n1 =  *start;
    if  (n1 == NULL)
        return ;
    n2 =  n1 -> next;
    if  (n2 == NULL)
        return ;
    n3 = n2 -> next;
    temp = n1 -> previous;
    n1 -> next = n3;
    n1 -> previous = n2;
    n2 -> previous = temp;
    n2 -> next = n1;
    if (n3 != NULL)
        n3 -> previous = n1;
    *start = n2;
    write (1, "sb\n", 3);
}

void ss(t_list *a, t_list *b)
{
    swap_a(&a);
    swap_b(&b);
    write (1, "ss\n", 3);
}

void push_a(t_list **dest, t_list **src)
{
    t_list  *newNode;
    if (*src == NULL) {
        return;
    }
    newNode = *src;
    *src = (*src)->next;
    newNode->next = *dest;
    *dest = newNode;  
    write(1, "pa\n", 3);
}

void push_b(t_list **dest, t_list **src)
{
    t_list  *newNode;
    if (*src == NULL) {
        return ;
    }
    newNode = *src;
    *src = (*src)->next;
    (*src)-> previous = NULL;
    newNode->next = *dest;
    *dest = newNode; 
    (*dest)-> previous = NULL; 
    write(1, "pb\n", 3);
}
