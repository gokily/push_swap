#include "push_swap.h"

t_pile	ft_ra(t_pile pile)
{
	ft_lnum_rotate(&pile.a);
	return (pile);
}

t_pile	ft_rb(t_pile pile)
{
	ft_lnum_rotate(&pile.b);
	return (pile);
}

t_pile	ft_rr(t_pile pile)
{
	ft_lnum_rotate(&pile.a);
	ft_lnum_rotate(&pile.b);
	return (pile);
}