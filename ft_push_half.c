/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_half.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:06:15 by gly               #+#    #+#             */
/*   Updated: 2019/03/08 09:08:04 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_operation.h"

static int		ft_findmedian(t_pile pile, int pd, int n)
{
	t_lnum	*lst;
	int		sorted[n];
	int		median;
	int		i;

	lst = pd == APILE ? pile.a : pile.b;
	i = 0;
	while (i < n)
	{
		sorted[i] = lst->n;
		lst = lst->next;
		i++;
	}
	ft_sort_inttab(sorted, n);
	median = sorted[n / 2 - 1];
	return (median);
}

static t_pile	*ft_rrot_n(t_dope *sol, t_pile *pile, int pd, int n)
{
	while (n-- > 0)
		if (!(pile = ft_add_ope(sol, pile, RROT * pd)))
			return (NULL);
	return (pile);
}

t_pile			*ft_push_half2pd(t_pile *pile, t_dope *sol, int pd, int n)
{
	int		median;
	int		half;
	int		n_push;
	int		n_rotate;

	n_push = 0;
	n_rotate = 0;
	half = pd == APILE ? n / 2 + n % 2 : n / 2;
	median = ft_findmedian(*pile, -pd, n);
	while (n_push < half)
	{
		if (pd == BPILE ? pile->a->n <= median : pile->b->n > median)
		{
			pile = ft_add_ope(sol, pile, PUSH * pd);
			n_push++;
		}
		else if (++n_rotate != 0)
			pile = ft_add_ope(sol, pile, NROT * -pd);
		if (pile == NULL)
			return (NULL);
	}
	if (ft_length_stack(pile, -pd) != n - half)
		pile = ft_rrot_n(sol, pile, -pd, n_rotate);
	return (pile);
}
