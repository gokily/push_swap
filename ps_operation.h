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
t_pile	ft_ope_sa(t_pile pile);
t_pile	ft_doope(t_pile pile, char *line, t_opp *tab);

#endif