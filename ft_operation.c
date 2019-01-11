/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:15:05 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 15:10:48 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_operation.h"
#include <stdlib.h>

int			ft_validope(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (1);
	else if (ft_strcmp(line, "sb") == 0)
		return (1);
	else if (ft_strcmp(line, "ss") == 0)
		return (1);
	else if (ft_strcmp(line, "pa") == 0)
		return (1);
	else if (ft_strcmp(line, "pb") == 0)
		return (1);
	else if (ft_strcmp(line, "sb") == 0)
		return (1);
	else if (ft_strcmp(line, "ra") == 0)
		return (1);
	else if (ft_strcmp(line, "rb") == 0)
		return (1);
	else if (ft_strcmp(line, "rr") == 0)
		return (1);
	else if (ft_strcmp(line, "rra") == 0)
		return (1);
	else if (ft_strcmp(line, "rrb") == 0)
		return (1);
	else if (ft_strcmp(line, "rrr") == 0)
		return (1);
	return (0);
}

t_opp	*ft_define_ope(void)
{
	t_opp	*tab;

	if (!(tab = malloc(sizeof(t_opp) * 11)))
		return (NULL);
	tab[0] = (t_opp){.type = "sa", .fct = &ft_sa};
	tab[1] = (t_opp){.type = "sb", .fct = &ft_sb};
	tab[2] = (t_opp){.type = "ss", .fct = &ft_ss};
	tab[3] = (t_opp){.type = "pa", .fct = &ft_pa};
	tab[4] = (t_opp){.type = "pb", .fct = &ft_pb};
	tab[5] = (t_opp){.type = "ra", .fct = &ft_ra};
	tab[6] = (t_opp){.type = "rb", .fct = &ft_rb};
	tab[7] = (t_opp){.type = "rr", .fct = &ft_rr};
	tab[8] = (t_opp){.type = "rra", .fct = &ft_rra};
	tab[9] = (t_opp){.type = "rrb", .fct = &ft_rrb};
	tab[10] = (t_opp){.type = "rrr", .fct = &ft_rrr};
	return (tab);
}

t_pile	*ft_doope(t_pile *pile, char *line, t_opp *tab)
{
	int		i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(line, tab[i].type) == 0)
			return (tab[i].fct(pile));
		i++;
	}
	return (pile);
}

t_pile	*ft_add_ope(t_dope *sol, t_pile *pile, int id)
{
	t_lope	*new;
	static t_opp	*opptab = NULL;
	
	if (opptab == NULL)
		opptab = ft_define_ope();
	if (!(new = malloc(sizeof(t_lope))))
		return (NULL);
	new->id = id;
	new->next = NULL;
	sol->tail->next = new;
	sol->tail = new;
	pile = opptab[id].fct(pile);
	return (pile);
}
