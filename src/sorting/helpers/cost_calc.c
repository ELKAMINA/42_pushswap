#include "../../../push_swap.h"

void  cost_calculation_pushtoB(t_list **head_A, t_list **head_B, int size)
{
    decircularing(head_A, size);
    t_list  *copy;
    int i;

    i = 1;
    copy = *head_A;
    get_index(head_A);
    while (copy)
    {
        if (copy->boolean == 'F')
        {
            if (copy->index == 1)
                push_b(head_B, head_A);
            else if (copy->index == 2)
            {
                swap_a(head_A);
                push_b(head_B, head_A);
            }
            else if (copy->index <= middle(ft_lstsize(*head_A)))
            {
                while (i < copy->index)
                {
                    rotate_a(head_A);
                    i++;
                }
                push_b(head_B, head_A);
            }
            else
            {
                i = copy->index;
                while (i <= ft_lstsize(*head_A))
                {
                    rev_rotate_a(head_A);
                    i++;
                }
                push_b(head_B, head_A);
            }
            copy = *head_A;
            get_index(head_A);
            i = 1;
        }
        else
            copy = copy->next;
        i = 1;
    }
}

void cost_calculation_toheadList(t_list **head)
{
    t_list *copy;
    int size;
    int i;

    copy = *head;
    i = 0;
    size = ft_lstsize(*head);
    get_index(head);
    while (copy)
    {
        if (copy->index == 1)
            copy->moves = 0;
        else if (copy->index == 2)
            copy->moves = 1;
        else if (copy->index <= middle(size))
        {
            while (i < copy->index - 1)
            {
                copy->moves += 1;
                i++;
            }
        }
        else
        {
            i = copy->index;
            while (i <= size)
            {
                copy->moves += 1;
                i++;
            }
        }
        copy = copy->next;
        i = 0;
    }
}

void get_cost_to_positionNodeB_inA(t_list **headA, t_list **headB)
{
    t_list  *copyA;
    t_list  *copyB;

    get_index(headA);
    get_index(headB);
    cost_calculation_toheadList(headB);
    cost_calculation_toheadList(headA);
    copyA = *headA;
    copyB = *headB;
    while(copyB)
    {
        copyB->posinA = check_pos_in_A(headA, copyB) + 1;
        while (copyB->posinA != copyA->index)
            copyA = copyA->next;
        copyB->total_moves = copyA->moves + copyB->moves + 1;
        copyB = copyB->next;
        copyA = *headA;
    }
}

void get_moves_to_zero(t_list **headA, t_list **headB)
{
    t_list *copyA;
    t_list *copyB;

    copyA = *headA;
    copyB = *headB;
    while (copyA)
    {
        copyA->moves = 0;
        copyA->total_moves = 0;
        copyA = copyA->next;
    }
     while (copyB)
    {
        copyB->moves = 0;
        copyB->total_moves = 0;
        copyB = copyB->next;
    }
}
