#include "push_swap.h"
#include "ps_operation.h"

int   ft_final_pos_last_elem_trio(t_lnum *stack, int (*fct)(int, int))
{
  int tmp;
  int pos;

  pos = 0;
  tmp = stack->next->next->n;
  if (fct(tmp, stack->next->n))
    pos++;
  if (fct(tmp, stack->n))
    pos++;
  return (pos);
}

t_pile  *ft_sort_three_0or1(t_pile *pile, t_dope *sol, int pd, int pos)
{
  pile = ft_add_ope(sol, pile, PUSH * -pd);
  pile = ft_add_ope(sol, pile, SWAP * pd);
  pile = ft_add_ope(sol, pile, PA);
  if (pos == 0)
    pile = ft_add_ope(sol, pile, SA);
  if (pd == BPILE)
    pile = ft_add_ope(sol, pile, PA);
  return (pile);
}

t_pile  *ft_push2a_thrice(t_pile *pile, t_dope *sol, int pd)
{
  if (pd == BPILE)
  {
    pile = ft_add_ope(sol, pile, PA);
    pile = ft_add_ope(sol, pile, PA);
    pile = ft_add_ope(sol, pile, PA);
  }
  return (pile);
}

t_pile  *ft_sort_three_loneflag(t_pile *pile, t_dope *sol, int pd, int pos)
{
  if (pos == 0)
    pile = ft_add_ope(sol, pile, RROT * pd);
  if (pos == 1)
    pile = ft_add_ope(sol, pile, NROT * pd);
  pile = ft_push2a_thrice(pile, sol, pd);
  return (pile);
}

t_pile  *ft_sort_three(t_pile *pile, t_dope *sol, int pd, int bswap)
{
  int pos;
  int swap;
  t_lnum  *stack;
  int   loneflag;
  
  stack = pd == APILE ? pile->a : pile->b;
  swap = pd == APILE ? stack->n > stack->next->n : stack->n < stack->next->n;
  pos = ft_final_pos_last_elem_trio(stack, 
    pd == APILE ? &ft_int_is_bigger : &ft_int_is_smaller);
  loneflag = ft_length_stack(pile, pd) == 3 ? 1 : 0;
  swap ^= loneflag && pos == 1 ? 1 : 0; 
  if (swap && bswap)
    pile = ft_add_ope(sol, pile, SS);
  else if (swap)
    pile = ft_add_ope(sol, pile, SWAP * pd);
  else if (bswap)
    pile = ft_add_ope(sol, pile, SWAP * -pd);
  if (loneflag)
    return(ft_sort_three_loneflag(pile, sol, pd, pos));
  if (pos == 2)
    ft_push2a_thrice(pile, sol, pd);
  else
    ft_sort_three_0or1(pile, sol, pd, pos);
  return (pile);
}