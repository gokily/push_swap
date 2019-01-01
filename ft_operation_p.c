#include "push_swap.h"

t_pile	ft_pa(t_pile pile)
{
	t_lnum	*tmp;

	if (pile.b == NULL)
		return (pile);
	tmp = pile.b;
	pile.b = pile.b->next;
	tmp->next = pile.a;
	pile.a = tmp;
	return (pile);
}
	
t_pile	ft_pb(t_pile pile)
{
	t_lnum	*tmp;

	if (pile.a == NULL)
		return (pile);
	tmp = pile.a;
	pile.a = pile.a->next;
	tmp->next = pile.b;
	pile.b = tmp;
	return (pile);
}
	