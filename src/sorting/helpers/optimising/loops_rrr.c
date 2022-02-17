#include "../../../../push_swap.h"

void loop_rrr_b(t_list **head_A, t_list **head_B, int movesb)
{
    int i = 1;
     while (i <= movesb)
    {
        rrr(head_A, head_B);
        i++;
    }
}

void loop_rrr_a(t_list **head_A, t_list **head_B, int movesa)
{
    int i = 1;
     while (i <= movesa)
    {
        rrr(head_A, head_B);
        i++;
    }
}

void sec_loop_rrb(int discard, t_list **head_B)
{
    while (discard != 0)
    {
        rev_rotate_b(head_B);
        discard++;
    }
}

void sec_loop_rra(int discard, t_list **head_A)
{
    while (discard != 0)
    {
        rev_rotate_a(head_A);
        discard--;
    }
}