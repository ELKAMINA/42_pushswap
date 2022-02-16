#include "../../../push_swap.h"

void ft_optimise(t_list **head_A, t_list **head_B, t_list *copyA, t_list *copyB)
{
 int discard;
 int i;
 t_list *same1;
 t_list *same2;

same1 = *head_A;
same2 = *head_B;
while (same1->data != copyA->data)
    same1 = same1->next;
while (same2->data != copyB->data)
    same2 = same2->next;
 discard = same1->moves - same2->moves;
 i = 1;
 if (same1->moves == 0 && same2->moves > 0)
    pushing_toheadListB(head_B, same2->index);
 else if (same2->moves == 0 && same1->moves > 0)
    pushing_toheadListA(head_A, same1->index, ft_lstsize(*head_A));
else if (same1->index <= middle(ft_lstsize(*head_A)) && same2->index <= middle(ft_lstsize(*head_B)))
 {
     if (discard == 0)
     {
        while (i <= copyB->moves)
        {
            rr(head_A, head_B);
            i++;
        }
     }
     else if (discard < 0)
     {
         while (i <= copyA->moves)
         {
            rr(head_A, head_B);
            i++;
         }
         //discard *= -1;
         while (discard != 0)
         {
            rotate_b(head_B);
            discard++;
         }
     }
    else
     {
         while (i <= copyB->moves)
         {
            rr(head_A, head_B);
            i++;
         }
         while (discard != 0)
         {
            rotate_a(head_A);
            discard--;
         }
     }  
 }
 else if (same1->index > middle(ft_lstsize(*head_A)) && same2->index > middle(ft_lstsize(*head_B)))
 {
    if (discard == 0)
    {
        while (i <= copyB->moves)
        {
            rrr(head_A, head_B);
            i++;
        }
    }
    else if (discard < 0)
    {
        while (i <= copyA->moves)
        {
            rrr(head_A, head_B);
            i++;
        }
        discard *= -1;
        while (discard != 0)
        {
            rev_rotate_b(head_B);
            discard--;
        }
    }
    else
    {
        while (i <= copyB->moves)
        {
            rrr(head_A, head_B);
            i++;
        }
        while (discard != 0)
        {
            rev_rotate_a(head_A);
            discard--;
        }
    }  
 }
 else
 {
    pushing_toheadListB(head_B, copyB->index);
    pushing_toheadListA(head_A, copyA->index, ft_lstsize(*head_A));
 }
}