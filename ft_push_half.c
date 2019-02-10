/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_half.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:06:15 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 17:41:49 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_operation.h"

int		ft_findmedian(t_pile pile, int pd, int n)
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

t_pile	*ft_push_half2pd(t_pile *pile, t_dope *sol, int pd, int n)
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
		else
		{
			pile = ft_add_ope(sol, pile, NROT * -pd);
			n_rotate++;
		}
		if (pile == NULL)
			return (NULL);
	}
	if (ft_length_stack(pile, -pd) == n - half)
		return (pile);
	while (n_rotate-- > 0)
	{
		if (!(pile = ft_add_ope(sol, pile, RROT * -pd)))
			return (NULL);
	}
	return (pile);
}