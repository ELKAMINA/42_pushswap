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

int update_pos(t_list **head, t_list *oneNode)
{
    int     size;
    int     i;
    int     pos;
    t_list *temp;

    temp = *head;
    i = 1;
    pos = 1;
    size = ft_lstsize(*head);
    while (temp->data != oneNode->data & i <= size)
    {
        pos++;
        temp = temp->next;
        i++;
    }
    return(pos);
}

int middle (t_list **head)
{
    int size;
    int mid;

    size = ft_lstsize(*head);
    if (size % 2 != 0)
    {
        mid = (size + 1) / 2;
    }
    else 
        mid = size / 2;
    return (mid);
}

void sortList_ascending(t_list **head) {  
    //Node current will point to head  
    t_list *current = *head;
    t_list *index = NULL;  
    int temp;  
        
    if(*head == NULL) {  
        return;  
    }  
    else {  
        while(current != NULL) {  
            //Node index will point to node next to current  
            index = current->next;  
                
            while(index != NULL) {  
                //If current node's data is greater than index's node data, swap the data between them  
                if(current->data > index->data) {  
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;  
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    }  
}  

void sortList_descending(t_list **head) {  
    //Node current will point to head  
    t_list *current = *head;
    t_list *index = NULL;  
    int temp;  
        
    if(*head == NULL) {  
        return;  
    }  
    else {  
        while(current != NULL) {  
            //Node index will point to node next to current  
            index = current->next;  
                
            while(index != NULL) {  
                //If current node's data is greater than index's node data, swap the data between them  
                if(current->data < index->data) {  
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;  
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    }  
}  
// struct Node* merge(struct Node* a, struct Node* b)
// {
//     // base cases
//     if (a == NULL) {
//         return b;
//     }
 
//     if (b == NULL) {
//         return a;
//     }
 
//     // pick either `a` or `b`, and recur
//     if (a->data <= b->data)
//     {
//         a->next = merge(a->next, b);
//         a->next->prev = a;
//         a->prev = NULL;
//         return a;
//     }
//     else {
//         b->next = merge(a, b->next);
//         b->next->prev = b;
//         b->prev = NULL;
//         return b;
//     }
// }

void sorting_under_hundred(t_list **head_A, t_list **head_B)
{
    int median;
    t_list  *bais;
    t_list  *copy;
    int length;
    int pos;
    int i;
    int j;
    int k;

    bais = *head_B;
    i = 1;
    j = 1;
    k = 0;
    median = calc_median(head_A);
    copy = *head_A;
    pos = 1;
    while (copy != NULL)
    {
        if (copy->data < median)
        {
            pos = update_pos(head_A, copy);
            if (pos == 1)
                push_b(head_B, head_A);
            else if (pos == 2)
            {
                swap_a(head_A);
                push_b(head_B, head_A);
            }
            else if (pos <= middle(head_A))
            {
                while (i < pos)
                {
                    rotate_a(head_A);
                    i++;
                }
                push_b(head_B, head_A);
            }
            else
            {
                i = pos;
                while (i <= ft_lstsize(*head_A))
                {
                    rev_rotate_a(head_A);
                    i++;
                }
                push_b(head_B, head_A);
            }
            copy = *head_A;
            i = 1;
        }
        else 
            copy = copy->next;
    }
    sortList_ascending(head_A);
    sortList_descending(head_B);
    length = ft_lstsize(*head_B);
    while (k < length)
    {
        push_a(head_A, head_B);
        k++;
    }
}



