#include "../../../push_swap.h"

void decircularing(t_list **A, int size)
{
  t_list *copy;
  int i;

  i = 0;
  copy = *A;
  copy->previous = NULL;
  while (i < size - 1)
  {
      copy = copy->next;
      i++;
  }
  copy->next = NULL;
}

// Ok envoie bien les bons dans B et laisse les T dans A



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