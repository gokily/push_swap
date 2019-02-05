/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:42:47 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 15:13:04 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_OPERATION_H
# define PS_OPERATION_H
# include "push_swap.h"

# define APILE 1
# define BPILE -1

# define SS 0
# define SWAP 1
# define PUSH 2
# define NROT 3
# define RROT 4
# define NRR 5
# define RRR 6
# define SA SWAP
# define SB -SWAP
# define PA PUSH
# define PB -PUSH
# define NRA NROT
# define NRB -NROT
# define RRA RROT
# define RRB -RROT

typedef t_pile	*(*t_funptr)(t_pile*);

typedef struct	s_opp
{
	char		*type;
	t_funptr	fct;
}				t_opp;

int		ft_validope(char *line);
t_opp	*ft_define_ope(void);
t_pile	*ft_doope(t_pile *pile, char *line, t_opp *tab);
t_pile  *ft_add_ope(t_dope *sol, t_pile *pile, int id);

t_pile	*ft_sa(t_pile *pile);
t_pile	*ft_sb(t_pile *pile);
t_pile	*ft_ss(t_pile *pile);
t_pile	*ft_pa(t_pile *pile);
t_pile	*ft_pb(t_pile *pile);
t_pile	*ft_ra(t_pile *pile);
t_pile	*ft_rb(t_pile *pile);
t_pile	*ft_rr(t_pile *pile);
t_pile	*ft_rra(t_pile *pile);
t_pile	*ft_rrb(t_pile *pile);
t_pile	*ft_rrr(t_pile *pile);

#endif
