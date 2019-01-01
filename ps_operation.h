#ifndef PS_OPERATION_H
# define PS_OPERATION_H
# include "push_swap.h"

typedef t_pile	(*t_funptr)(t_pile);

typedef struct	s_opp
{
	char		*type;
	t_funptr	fct;
}				t_opp;

int		ft_validope(char *line);
t_opp	*ft_define_ope(void);
t_pile	ft_doope(t_pile pile, char *line, t_opp *tab);

t_pile	ft_sa(t_pile pile);
t_pile	ft_sb(t_pile pile);
t_pile	ft_ss(t_pile pile);
t_pile	ft_pa(t_pile pile);
t_pile	ft_pb(t_pile pile);
t_pile	ft_ra(t_pile pile);
t_pile	ft_rb(t_pile pile);
t_pile	ft_rr(t_pile pile);
t_pile	ft_rra(t_pile pile);
t_pile	ft_rrb(t_pile pile);
t_pile	ft_rrr(t_pile pile);

#endif