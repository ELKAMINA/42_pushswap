#include "push_swap.h"

void swap_a(t_list  *start)
{
    t_list  *n1;
    t_list  *n2;
    t_list  *n3;
    t_list  *temp;


    n1 =  start;
    if  (n1 == NULL)
        return ;
    // Ici comme la fonction recoit double pointeur => https://stackoverflow.com/questions/14766683/pointing-dereference-inside-a-struct-error
    n2 =  n1 -> next;
    if  (n2 == NULL)
        return ;
    //write (1, "sa\n", 3);
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

void swap_b(t_list  *start)
{
    t_list  *n1;
    t_list  *n2;
    t_list  *n3;
    t_list  *temp;


    n1 =  start;
    if  (n1 == NULL)
        return ;
    // Ici comme la fonction recoit double pointeur => https://stackoverflow.com/questions/14766683/pointing-dereference-inside-a-struct-error
    n2 =  n1 -> next;
    if  (n2 == NULL)
        return ;
    //write (1, "sb\n", 3);
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

void ss(t_list *a, t_list *b)
{
    swap_a(a);
    swap_b(b);
    //write (1, "ss\n", 3);
}

void push_a(t_list **dest, t_list **src)
{
    // helper function which adds a new node at the top of a list
    t_list  *newNode;
    if (*src == NULL) {
        return;
    }
 
    newNode = *src;  // the front source node
    *src = (*src)->next;    // advance the source pointer
    newNode->next = *dest;           // link the old dest off the new node
    *dest = newNode;  
    //write(1, "pa\n", 3);
}

void push_b(t_list **dest, t_list **src)
{
    // helper function which adds a new node at the top of a list
    t_list  *newNode;
    if (*src == NULL) {
        return;
    }
 
    newNode = *src;  // the front source node
    *src = (*src)->next;    // advance the source pointer
    newNode->next = *dest;           // link the old dest off the new node
    *dest = newNode; 
    //write(1, "pb\n", 3);
}