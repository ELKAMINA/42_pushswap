#include "push_swap.h"

int calc_median(t_list **head)
{
    int max;
    int min;
    int median;
    t_list *start;
    t_list *start2;

    start = *head;
    start2 = *head;
    min = lower(&start);
    max = higher(&start2);
    median = (max - min)/2;
    return(median);
}

void get_index(t_list **head)
{
    t_list *copy;
    int    i;

    copy = *head;
    i = 1;
    while(copy)
    {
        copy->index = i;
        copy = copy->next;
        i++;
    }
}
int update_pos(t_list **head, t_list *oneNode, int size)
{
    //int     size;
    int     i;
    int     pos;
    t_list *temp;

    temp = *head;
    i = 1;
    pos = 1;
    //size = ft_lstsize(*head);
    while (temp->data != oneNode->data & i <= size)
    {
        pos++;
        temp = temp->next;
        i++;
    }
    return(pos);
}

int middle (int size)
{
    int mid;

    if (size % 2 != 0)
    {
        mid = (size + 1) / 2;
    }
    else 
        mid = size / 2;
    return (mid);
}

void cost_calculation_pushtoB(t_list **head_A, t_list **head_B, int size)
{
    t_list  *copy;
    t_list  *test;
    int i;
    int j;
    int real_size;

    i = 0;
    j = 1;
    copy = *head_A;
    test = *head_B;
    real_size = size;
    while (j < real_size)
    {
        if (copy->boolean == 'F')
        {
            copy->pos = update_pos(head_A, copy, size);
            //printf("(%d)", pos);
            if (copy->pos == 1)
                push_b(head_B, head_A);
            else if (copy->pos == 2)
            {
                swap_a(head_A);
                push_b(head_B, head_A);
            }
            else if (copy->pos <= middle(size))
            {
                while (i < copy->pos)
                {
                    rotate_a(head_A);
                    i++;
                }
                push_b(head_B, head_A);
            }
            else
            {
                i = copy->pos;
                while (i <= size)
                {
                    rev_rotate_a(head_A);
                    i++;
                }
                push_b(head_B, head_A);
            }
            // printf("COPY if boolean == (%d)\n", copy->data);
            // printf("HEAD A if boolean == (%d)\n", (*head_A)->data);  
            copy = *head_A;
            size--;
        }
        else
            copy = copy->next;
        j++;
    }
    copy->next = NULL;
}

void cost_calculation_toheadList(t_list **head)
{
    t_list *copy;
    int size;
    int i;
    int j;

    copy = *head;
    i = 0;
    j = 0;
    size = ft_lstsize(*head);
    //printf("%d\n", size);
    while (j < size)
    {
        //copy->pos = update_pos(head, copy, size);
        get_index(head);
        printf(" @@ %d @@@ %d ---\n", copy->index, copy->data);
        if (copy->index == 1)
            copy->moves = 0;
        else if (copy->index == 2)
            copy->moves = 1;
        else if (copy->index < middle(size))
        {
            while (i < copy->index)
            {
                copy->moves += 1;
                i++;
            }
        }
        else
        {
            i = copy->index;
            //printf("COPY INDEX : @@ %d\n", i);
            while (i <= size)
            {
                // printf("COPY INDEX : @@ %d @@@ %d\n", copy->index, i);
                copy->moves += 1;
                i++;
            }
        }
        j++;
        copy = copy->next;
    }
}

void circularing_LL(t_list **A)
{
    t_list  *copy;
    t_list  *head;

    copy = *A;
    head = *A;
    while (copy->next != NULL)
        copy = copy->next;
    copy->next = head;
    head->previous = copy;
}


int max_sort(t_list   **head, int size)
{
    int min_int;
    int max;
    int i;
    
    i = 0;
    min_int = -2147483648;
    max = min_int;
    while (i < size)
    {
        if  (max < (*head)->sort)
            max = (*head)->sort;
        *head = (*head)->next;
        i++;
    }
    return (max);
}

// int min_moves_toHead(t_list   **head, int size)
// {
//     int max;
//     int max_int;
//     int i;
    
//     i = 0;
//     max_int = 2147483647;
//     min = max_int
//     while (i < size)
//     {
//         if  (min > (*head)->moves)
//             min = (*head)->moves;
//         *head = (*head)->next;
//         i++; 
//     }
//     return (max);
// }

void node_to_sendtoB(t_list **A, t_list **B, int size)
{
    t_list *copy;
    int sort_max;
    t_list *moving;
    t_list *current;
    // t_list  *test;

    copy = *A;
    // test = (*A);
    sort_max = max_sort(A, size);
    while (copy->sort != sort_max)
        copy = copy->next;
    copy->boolean = 'T';
    moving = copy;
    current = copy->next;
    while (current != copy)
    {
        if (current->data > moving->data)
        {
            moving = current;
            moving->boolean = 'T';
        }
        current = current->next;
    }
    cost_calculation_pushtoB(A, B, size);
    // i = 0;
    // while(i < size)
    // {
    //     printf("[%d] --- {%c}\n", test->data, test->boolean);
    //     test = test->next;
    //     i++;
    // }

}


// void get_total_movestoA_perNode(t_list **headA, t_list **headB)
// {
//     t_list  *copyA;
//     t_list  *copyB;

//     copyA = *headA;
//     copyB = *headB;
//     while(copy)
//     {

//         check_pos_in_A
//     }
// }
// void get_total_moves(t_list **head)
// {
//     t_list  *copy;
//     int i;

//     while(copy)
//     {
//         copy->total_moves = (copy->moves) + 
//     }
// }

int check_pos_in_A(t_list **A, t_list *oneNode, int size)
{
    t_list *copy;
    int i;
    int j;

    copy = *A;
    i = 1;
    j = 0;

    while (j < size)
    {
          if (copy->data < oneNode->data && copy->next->data > oneNode->data)
            return (i);
        copy = copy->next;
        i++;
        j++;
    }
    return (0);
}

void get_cost_to_positionNodeB_inA(t_list **headA, t_list **headB)
{
    t_list  *copyA;
    t_list  *copyB;
    int i;
    int size;
    int position_inA;

    position_inA = 0;
    i = 0;
    size = ft_lstsize(*headB);
    copyA = *headA;
    copyB = *headB;
    //printf("%d", ft_lstsize(copyB));
    while(copyB)
    {
        position_inA = check_pos_in_A(headA, copyB, ft_lstsize(*headB)) + 1;
        //printf("Position : [%d] **** %d\n", position_inA, copyB->data);
        //cost_calculation_toheadList(headA);
        cost_calculation_toheadList(headB);
        get_index(headA);
        while (position_inA != copyA->index)
            copyA = copyA->next;
        //printf(": [%d]\n", copyA->data);
        copyB->total_moves = copyA->moves + copyB->moves + 1;
        //printf("Total moves : [%d] **** %d\n", copyB->moves, copyB->data);
        copyB = copyB->next;
    }
}

void 	sorting_above_six(t_list **head_A, t_list **head_B)
{
    t_list *copy;
    t_list *moving;
    t_list *current;
    t_list  *bais;
    int size;
    int i;
    int j;

    bais = *head_B;
    i = 0;
    j = 0;
    size = ft_lstsize(*head_A);
    circularing_LL(head_A);
    copy = *head_A;
    while(i < size)
    {
        moving = copy;
        current = copy->next;
        while (current != copy)
        {
            if (current->data > moving->data)
            {
                moving = current;
                copy->sort += 1;
            }
            current = current->next;
        }
        copy = copy->next;
        i++;
    }
    node_to_sendtoB(head_A, head_B, size);
    get_cost_to_positionNodeB_inA(head_A, head_B);
    // write(1, "A\n", 2);
    // while (*head_A)
	// {
	// 	printf("DATA = [%d]\n", (*head_A)->data);
	// 	*head_A = (*head_A)->next;
	// }
    //cost_calculation_toheadList(head_B);
    //cost_calculation_toheadList(head_A);
    // write(1, "B\n", 2);
    //get_index(head_A);
    
    // while(*head_B)
    // {
    //     printf("(%d)-- (%d)\n",(*head_B)->data, (*head_B)->total_moves);
    //     *head_B = (*head_B)->next;
    // }
    // printf("(%d)\n", check_pos_in_A(head_A, test, size));
    // printf("(%d)\n", check_pos_in_A(head_A, test->next->next, size));
    // i = 0;
    // while(i < size)
    // {
    //     printf("[%d] --- {%d}\n", test->data, test->sort);
    //     test = test->next;
    //     i++;
    // }
}


