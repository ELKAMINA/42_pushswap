#include "push_swap.h"

// void rotate_a(t_list **a)
// {
//     // helper function which adds a new node at the top of a list
//     t_list  *newNode;
//     t_list  *ptr1;

//     newNode = *a;
//     if (!*a || !(*a)->next)
//         return;
//     while (newNode -> next -> next)
//         newNode = newNode -> next;
//     // En sortant de la boucle, on sarrete à lavant derniere valeur 
//     // newNode -> next -> next correspond a NULL. On crée donc une double liste chainée circulaire ou le dernier élément pointe vers le premier.
//     newNode -> next -> next = *a;

//     //Ici, Head prend donc la valeur de newNode -> next, qui est la derniere valeur.
//     *a = newNode -> next;
//     newNode -> next = NULL;
//     ptr1 = (*a) -> next;
//     ptr1 -> previous = *a;
//     //write(1, "ra\n", 3);
// }

void rotate_a(t_list **a)
{
    // helper function which adds a new node at the top of a list
    t_list  *newNode;
    //t_list  *ptr1;

    newNode = *a;
    if (!*a || !(*a)->next)
        return;
    while (newNode -> next -> next)
        newNode = newNode -> next;
    // En sortant de la boucle, on sarrete à lavant derniere valeur 
    // newNode -> next -> next correspond a NULL. On crée donc une double liste chainée circulaire ou le dernier élément pointe vers le premier.
    //newNode -> next -> next = *a;
    (*a) -> previous = newNode -> next -> next;
    //(*a) -> next = NULL;
    newNode -> next -> next = (*a);
    (*a) = (*a) -> next;
    (*a) -> previous = NULL;
    newNode -> next -> next -> next =  NULL;
    //Ici, Head prend donc la valeur de newNode -> next, qui est la derniere valeur.
    //newNode-> next -> next -> next = NULL;
    write(1, "ra\n", 3);
}

void rotate_b(t_list **b)
{
    // helper function which adds a new node at the top of a list
    t_list  *newNode;
    //t_list  *ptr1;

    newNode = *b;
    if (!*b || !(*b)->next)
        return;
    while (newNode -> next -> next)
        newNode = newNode -> next;
    // En sortant de la boucle, on sarrete à lavant derniere valeur 
    // newNode -> next -> next correspond a NULL. On crée donc une double liste chainée circulaire ou le dernier élément pointe vers le premier.
    newNode -> next -> next = newNode-> previous;
    newNode -> previous -> previous = newNode-> next -> next;
    newNode -> next -> next -> next = NULL;
    //Ici, Head prend donc la valeur de newNode -> next, qui est la derniere valeur.
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

// void rev_rotate_a(t_list **a)
// {
//     t_list  *newNode;

//     newNode = *a;
//     if (!*a || !(*a)->next)
//         return ;
//     while (newNode -> next -> next)
//         newNode = newNode -> next;
//     newNode -> next -> next = *a;
//     *a = (*a) -> next;
//     newNode -> next -> next -> next = NULL;
//     newNode -> next -> next -> previous = newNode -> next;
//     //write (1, "rra\n", 4);
// }

void rev_rotate_a(t_list **a)
{
    t_list  *newNode;

    newNode = *a;
    if (!*a || !(*a)->next)
        return ;
    while (newNode -> next -> next)
        newNode = newNode -> next;
    // newNode -> next -> next = *a;
    // newNode -> previous -> previous = newNode -> next;
    // *a = newNode -> next;
    // newNode -> next = NULL;
    newNode->next->next = *a;
    newNode->previous->previous = newNode->next;
    *a = newNode->previous->previous;
    newNode->next = NULL;
    write (1, "rra\n", 4);
}

void rev_rotate_b(t_list **b)
{
    t_list  *newNode;

    newNode = *b;
    if (!*b || !(*b)->next)
        return ;
    while (newNode -> next -> next)
        newNode = newNode -> next;
    newNode -> next -> next = *b;
    newNode -> previous -> previous = newNode -> next;
    *b = newNode -> next;
    newNode -> next = NULL;
    write (1, "rrb\n", 4);
}