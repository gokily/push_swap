#include "push_swap.h"
#include "ps_operation.h"

t_pile *ft_sort_four(t_pile *pile, t_dope *sol, int pd)
{
  if (!(pile = ft_push_half2pd(pile, sol, -pd, 4)))
    return (NULL);
  if (pile == NULL)
    return (NULL);
  if (pile->a->n > pile->a->next->n)
  {
    if (pile->b->n < pile->b->next->n)
      pile = ft_add_ope(sol, pile, SS);
    else
      pile = ft_add_ope(sol, pile, SA);
  }
  else if (pile->b->n < pile->b->next->n)
    pile = ft_add_ope(sol, pile, SB);
  return (pile);
}

t_pile *ft_sort_five(t_pile *pile, t_dope *sol, int pd)
{
  int bswap;

  bswap = 0;
  if (!(pile = ft_push_half2pd(pile, sol, -pd, 5)))
    return (NULL);
  if (pile->b->n < pile->b->next->n)
    bswap = 1;
  pile = ft_sort_three(pile, sol, APILE, bswap);
  return (pile);
}

t_pile *ft_sort_end(t_pile *pile, t_dope *sol, int pd, int n)
{
  if (n == 3)
    return (ft_sort_three(pile, sol, pd, 0));
  else if (n == 4)
    ft_sort_four(pile, sol, pd);
  else
    ft_sort_five(pile, sol, pd);
  pile = ft_add_ope(sol, pile, PA);
  pile = ft_add_ope(sol, pile, PA);
  return (pile);
}