#include "../../../push_swap.h"

void pushing_toheadListB(t_list **headB, int index)
{
    t_list *copy;
    int size;
    int i;

    i = 0;
    copy = *headB;
    size = ft_lstsize(*headB);
    get_index(headB);
    while (copy->index != index)
        copy = copy->next;
    if (copy->index == 1)
        return ;
    else if (copy->index == 2)
        swap_b(headB);
    else if (copy->index <= middle(size))
    {
        while (i < copy->index - 1)
        {
            rotate_b(headB);
            i++;
        }
    }
    else
    {
        i = copy->index;
        while (i <= size)
        {
            rev_rotate_b(headB);
            i++;
        }
    }
}

void pushing_toheadListA(t_list **headA, int index, int size)
{
    t_list *copy;
    int i;

    i = 0;
    copy = *headA;
    get_index(headA);
    while (copy->index != index)
        copy = copy->next;
    if (copy->index == 1)
        return ;
    else if (copy->index == 2)
        rotate_a(headA);
    else if (copy->index <= middle(size))
    {
        while (i < copy->index - 1)
        {
            rotate_a(headA);
            i++;
        }
    }
    else
    {
        i = copy->index;
        while (i <= size)
        {
            rev_rotate_a(headA);
            i++;
        }
    }
}

void node_to_sendtoB(t_list **A, t_list **B, int size)
{
    t_list *copy;
    int     sort_max;
    t_list *moving;
    t_list *current;

    copy = *A;
    sort_max = max_sort(A, size);
    while (copy->sort != sort_max)
        copy = copy->next;
    copy->boolean = 'T';
    //printf("FIRST ELEMENT: DATA------> %d, SORT : %d ---> Boolean : %c\n", copy->data, copy->sort, copy->boolean);
    moving = copy;
    current = copy->next;
    while (current != copy)
    {
        if (current->data > moving->data)
        {
            moving = current;
            moving->boolean = 'T';
        }
        //printf("to stack B or not : DATA------> %d, SORT : %d ---> Boolean : %c\n", current->data, current->sort, current->boolean);
        current = current->next;
    }
    cost_calculation_pushtoB(A, B, size);
}

void pushing_to_A(t_list **head_A, t_list **head_B)
{
    t_list *copyA;
    t_list *copyB;
    t_list *sec_copyB;

    copyA = *head_A;
    copyB = *head_B;    
    sec_copyB = *head_B;
    get_moves_to_zero(head_A, head_B);
    get_cost_to_positionNodeB_inA(head_A, head_B);
    while(copyB->total_moves != min_moves(&sec_copyB))
        copyB = copyB->next;
    //printf("test\n");
    copyB->posinA = check_pos_in_A(head_A, copyB) + 1;
    get_index(head_A);
    while (copyA->index != copyB->posinA)
        copyA = copyA->next;
    //printf("A to be sent ------> %d, B to be sent : %d\n", copyA->data, copyB->data);
    ft_optimise(head_A, head_B, copyA, copyB);
    // pushing_toheadListB(head_B, copyB->index);
    // pushing_toheadListA(head_A, copyA->index, ft_lstsize(*head_A));
    push_a(head_A, head_B);
    
}