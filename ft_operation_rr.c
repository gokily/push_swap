#include "push_swap.h"

t_pile	ft_rra(t_pile pile)
{
	ft_lnum_rrotate(&pile.a);
	return (pile);
}

t_pile	ft_rrb(t_pile pile)
{
	ft_lnum_rrotate(&pile.b);
	return (pile);
}

t_pile	ft_rrr(t_pile pile)
{
	ft_lnum_rrotate(&pile.a);
	ft_lnum_rrotate(&pile.b);
	return (pile);
}