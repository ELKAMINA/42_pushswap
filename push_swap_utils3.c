#include "push_swap.h"

int higher(t_list   **head)
{
    int min_int;
    int max;
    
    min_int = -32767;
    max = min_int;
    while ( *head != NULL)
    {
        if  (max < (*head)->data)
            max = (*head)->data;
        *head = (*head)->next;
    }
    return (max);
}

int lower(t_list   **head)
{
    int max_int;
    int min;
    
    max_int = 32767;
    min = max_int;
    while ( *head != NULL)
    {
        if  (min > (*head)->data)
            min = (*head)->data;
        *head = (*head)->next;
    }
    return (min);
}

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
    else if (nb1 < nb2 && nb2 > nb3 && nb3 < nb1)
        rev_rotate_a(head);
    else
        return ;
}

void sorting_five(t_list **head_A, t_list **head_B)
{
    // int nb1;
    // int nb2;
    // int nb3;

    // nb1 = (*head)->data;
    // nb2 = (*head)->next->data;
    // nb3 = (*head)->next->next->data;
    // nb4 = nb3->next->data;
    // nb5 = nb4->next->data;

    //printf("_____%d %d %d_______\n", nb1, nb2, nb3);
    push_b(head_B, head_A);
    push_b(head_B, head_A);
    sorting_three(head_A);
    push_a(head_A, head_B);
    rotate_a(head_A);
    push_a(head_A, head_B);
    while (*head_A)
	{
		printf("A = [%d]\n", (*head_A)->data);
		*head_A = (*head_A)->next;
	}
    while (*head_B)
	{
		printf("B = [%d]\n", (*head_B)->data);
		*head_B = (*head_B)->next;
	}
}