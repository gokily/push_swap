#include "push_swap.h"
#include "ps_operation.h"

int   ft_lnum_sorted_incr(t_lnum *lst)
{
  t_lnum *tmp;
  
  if (lst == NULL || lst->next == NULL)
    return (1);
  tmp = lst;
  while (tmp->next != NULL)
  {
    if (tmp->n > tmp->next->n)
      return (0);
    tmp = tmp->next;
  }
  return (1);
}

// this can be refactor to take a function as an argument. So we can combine the function above with it.
int   ft_lnum_sorted_decr(t_lnum *lst)
{
  t_lnum *tmp;
  
  if (lst == NULL || lst->next == NULL)
    return (1);
  tmp = lst;
  while (tmp->next != NULL)
  {
    if (tmp->n < tmp->next->n)
      return (0);
    tmp = tmp->next;
  }
  return (1);
}

int		ft_pile_is_sorted(t_pile *pile, t_dope *sol)
{
	if (pile->b == NULL)
	  return (ft_lnum_sorted_incr(pile->a));
  if (ft_lnum_sorted_incr(pile->a) && ft_lnum_sorted_decr(pile->b))
  {
    while (pile->b != NULL)
    {
      if(!(pile = ft_add_ope(sol, pile, PA)))
        return (0);
    }
    return (1);
  }
  return (0);
}