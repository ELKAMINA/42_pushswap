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
    while ((temp->data != oneNode->data) & (i <= size))
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

void decircularing(t_list **A, int size)
{
 printf("test\n");
  t_list *copy;
  int i;

  i = 0;
  copy = *A;
  copy->previous = NULL;
  //printf("%d ===\n", copy->data);
  while (i < size - 1)
  {
      copy = copy->next;
      i++;
  }
  copy->next = NULL;
}

// Ok envoie bien les bons dans B et laisse les T dans A
void  cost_calculation_pushtoB(t_list **head_A, t_list **head_B, int size)
{
    decircularing(head_A, size);
    t_list  *copy;
    int i;

    i = 1;
    copy = *head_A;
    while (copy)
    {
        if (copy->boolean == 'F')
        {
            copy->pos = update_pos(head_A, copy, size);
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
            copy = *head_A;
        }
        else
            copy = copy->next;
    }
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
    get_index(head);
    while (j < size)
    {
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
            while (i <= size)
            {
                copy->moves += 1;
                i++;
            }
        }
        j++;
        copy = copy->next;
    }
}

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
        swap_b(*headB);
    else if (copy->index < middle(size))
    {
        while (i < copy->index)
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
   //printf("SIZE = %d\n", size);
    get_index(headA);
    while (copy->index != index)
        copy = copy->next;
    
    if (copy->index == 1)
        return ;
    else if (copy->index == 2)
        rotate_a(headA);
    else if (copy->index < middle(size))
    {
        while (i < copy->index)
        {
            rotate_a(headA);
            i++;
        }
    }
    else
    {
        i = copy->index;
        //printf("i = %d ---- Index %d\n",i, copy->index);
        while (i <= size)
        {
            rev_rotate_a(headA);
            i++;
            //printf("%d %d\n", i, );
        }
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

int min_moves(t_list   **head, int size)
{
    int min;
    t_list *copy;
    int max_int;
    int i;
    
    i = 0;
    copy = *head;
    max_int = 2147483647;
    min = max_int;
    while (i < size)
    {
        //printf("FONCTION : [%d] ---- [%d]\n", copy->data, copy->total_moves);
        if  (min > copy->total_moves)
            min = copy->total_moves;
        copy = copy->next;
        i++; 
    }
    return (min);
}

// OK fonction envoie liste circulaire A avec ceux qui sont true et false
void node_to_sendtoB(t_list **A, t_list **B, int size)
{
    t_list *copy;
    int     sort_max;
    t_list *moving;
    t_list *current;

    copy = *A;
    sort_max = max_sort(A, size);
    // OK SORT MAX : printf("sort max ===>%d\n", sort_max);
    while (copy->sort != sort_max)
        copy = copy->next;
    // OK COPY AVEC SORT MAX :printf("COPY avec MAX SORT ===>%d\n", copy->data);
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
        // OK BOOLEAN printf("COPY avec BOOLEAN = data : %d ----> %c\n", current->data, current->boolean);
        current = current->next;
    }
    cost_calculation_pushtoB(A, B, size);
}

int check_pos_in_A(t_list **A, t_list *oneNode)
{
    t_list *copy;
    t_list *head_exception;
    int i;

    copy = *A;
    head_exception = *A;
    i = 1;
    //printf("SIZE = %d\n", size);
    while (copy)
    {
        if (copy->data < oneNode->data && copy->next->data > oneNode->data)
        {
            //printf("node : 5/2/3 : %d --> i = 4/4/2 :  %d\n", oneNode->data, i);
            return (i);
        }
        if (copy->next == NULL)
        {
            if (copy->data < oneNode->data && head_exception->data > oneNode->data)
                return (i);
        }
        copy = copy->next;
        i++;
    }
    //printf(" A : %d \n", head_exception->data);
    return (0);
}

void get_cost_to_positionNodeB_inA(t_list **headA, t_list **headB)
{
    t_list  *copyA;
    t_list  *copyB;
    int position_inA;

    position_inA = 0;
    copyA = *headA;
    copyB = *headB;
    cost_calculation_toheadList(headB);
    cost_calculation_toheadList(headA);
    get_index(headA);
    // OK MOVES, INDEX ET DATA
        // write(1, "A\n", 2);
        // while (copyA)
        // {
        //     printf("[%d]--->[%d]--->[%d] \n", copyA->data, copyA->moves, copyA->index);
        //     copyA = copyA->next;
        // }
        // write(1, "B\n", 2);
        // while (copyB)
        // {
        //     printf("[%d]--->[%d]--->[%d] \n", copyB->data, copyB->moves, copyB->index);
        //     copyB = copyB->next;
        // }
    while(copyB != NULL)
    {
        position_inA = check_pos_in_A(headA, copyB) + 1;
       // OK bon calcul printf("data =[%d] **** position in A = %d\n", copyB->data, position_inA);
        //cost_calculation_toheadList(headA);
        get_index(headA);
        while (position_inA != copyA->index)
            copyA = copyA->next;
        //printf(": [%d]\n", copyA->data);
        //printf(": [%d]\n", copyA->moves);
        copyB->total_moves = copyA->moves + copyB->moves + 1;
        //OK bon calcul : printf("Total moves : data = [%d] **** totalmoves = %d\n", copyB->data, copyB->total_moves);
        copyB = copyB->next;
        copyA = *headA;
    }
}

void pushing_to_A(t_list **head_A, t_list **head_B)
{
    t_list *copyA;
    t_list *copyB;
    t_list *sec_copyB;
    int     position;

    copyA = *head_A;
    copyB = *head_B;    
    sec_copyB = *head_B;    
    cost_calculation_toheadList(head_B);
    get_cost_to_positionNodeB_inA(head_A, head_B);
    // printf("COPY B DATA SECOND TOUR-->%d\n", copyB->data);
    // printf("COPY A DATA SECOND TOUR-->%d\n", copyA->data);
    cost_calculation_toheadList(head_A);
    write(1, "B\n",2);
    while(copyB)
    {
        printf("data =[%d] **** totalmoves = %d\n", copyB->data, copyB->total_moves);
        copyB = copyB->next;
    }
    write(1, "A\n",2);
    while(copyA)
    {
        printf("data =[%d] **** totalmoves = %d\n", copyA->data, copyA->total_moves);
        copyA = copyA->next;
    }
    // printf("cost to head A DATA SECOND TOUR-->%d\n", copyA->moves);
    // printf("%d ---- cost to head B DATA SECOND TOUR-->%d\n", copyB->data, copyB->moves);
    //printf("cost to head A DATA SECOND TOUR-->%d\n", copyA->moves);
    // printf("%d ---- cost to head B DATA SECOND TOUR-->%d\n", copyB->data, copyB->moves);
    // printf("Total moves : [%d] **** %d\n", copyB->next->moves, copyB->next->data);
    // on veut se placer au niveau du maillon dont le nombre total de mouvement est inférieur.
    //printf("MIN MVOES --> %d\n", min_moves((head_B), ft_lstsize(*head_B)));
    //min_moves((head_B), ft_lstsize(*head_B));
    // copyB = copyB->next->next;
    while(copyB->total_moves != min_moves((&sec_copyB), ft_lstsize(sec_copyB)))
        copyB = copyB ->next;
    //printf("--- %d --- \n", copyB->total_moves);
    // // Ici, on envoie l'élement concerné à la tête de la liste
    pushing_toheadListB(head_B, copyB->index);
    // // Ici, on checke à quel niveau dans A, il pouvoir se placer pour être dans l'ordre croissant.
    position = check_pos_in_A(head_A, copyB) + 1;
    //printf("--- POSITION %d --- \n", position);

    // // Ici, on se place au niveau du maillon dans A qui est en 4ème position
    // get_index(head_A);
    while (copyA->index != position)
    {
        copyA = copyA->next;

    }
    //printf("DATA = %d ---> INDEX=%d\n", copyA->data, copyA->index);
    pushing_toheadListA(head_A, copyA->index, ft_lstsize(*head_A));
    // while (copyA)
	// {
	// 	printf("A = [%d]\n", copyA->data);
	// 	copyA = copyA->next;
	// }
    // while (copyB)
	// {
	// 	printf("B = [%d]\n", copyB->data);
	// 	copyB = copyB->next;
	// }
    push_a(head_A, head_B);
    // printf("testC = %p\n", (&*head_A));
    // printf("testD = %p\n", (&*head_B));
    // printf("--- %d --- \n", (*head_A)->data);
}

void last_sort (t_list **headA)
{
    t_list *copy;
    t_list *copy2;
    int min;

    get_index(headA);
    copy = *headA;
    copy2 = *headA;
    min = lower(&copy2);
    //printf("%d\n", ft_lstsize(*headA));
    while (copy->data != min)
        copy = copy->next;
    pushing_toheadListA(headA, copy->index, ft_lstsize(*headA));
}

void 	sorting_above_six(t_list **head_A, t_list **head_B)
{
    t_list *copy;
    t_list *moving;
    t_list *current;
    int sizeA;
    int i;

    i = 0;
    // printf( "I ====> %d\n", i);
    sizeA = ft_lstsize(*head_A);
    circularing_LL(head_A);
    while(i < sizeA)
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
        //printf("[%d] ==> [%d]\n", copy->data, copy->sort);
        copy = copy->next;
        i++;
    }
    node_to_sendtoB(head_A, head_B, sizeA);
    get_cost_to_positionNodeB_inA(head_A, head_B);
    // while (*head_B != NULL)
    pushing_to_A(head_A, head_B);
    // //pushing_to_A(head_A, head_B);
    // last_sort(head_A);
}