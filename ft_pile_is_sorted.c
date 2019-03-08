/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_is_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:09:35 by gly               #+#    #+#             */
/*   Updated: 2019/02/21 12:10:42 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_operation.h"

int		ft_lnum_fsorted(t_lnum *lst, int (*fct)(int, int))
{
	t_lnum *tmp;

	if (lst == NULL || lst->next == NULL)
		return (1);
	tmp = lst;
	while (tmp->next != NULL)
	{
		if (fct(tmp->n, tmp->next->n))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_pile_is_sorted(t_pile *pile, t_dope *sol)
{
	if (pile->b == NULL)
		return (ft_lnum_fsorted(pile->a, &ft_int_is_bigger));
	if (ft_lnum_fsorted(pile->a, &ft_int_is_bigger) &&
			ft_lnum_fsorted(pile->b, &ft_int_is_smaller))
	{
		while (pile->b != NULL)
		{
			if (!(pile = ft_add_ope(sol, pile, PA)))
				return (0);
		}
		return (1);
	}
	return (0);
}
