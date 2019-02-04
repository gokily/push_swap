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

t_pile	*ft_push_half2b(t_pile *pile, t_dope *sol, int n)
{
	int		median;
	int		half;
	int		n_push;
	int		n_rotate;

	n_push = 0;
	n_rotate = 0;
	half = n / 2;
	median = ft_findmedian(*pile, APILE, n);
	while (n_push < half)
	{
		if (pile->a->n <= median)
		{
			pile = ft_add_ope(sol, pile, PB);
			n_push++;
		}
		else
		{
			pile = ft_add_ope(sol, pile, NRA);
			n_rotate++;
		}
		if (pile == NULL)
			return (NULL);
	}
	while (n_rotate-- > 0)
	{
		if (!(pile = ft_add_ope(sol, pile, RRA)))
			return (NULL);
	}
	return (pile);
}

t_pile	*ft_push_half2a(t_pile *pile, t_dope *sol, int n)
{
	int		n_push;
	int		n_rotate;
	int		median;
	int		half;

	n_push = 0;
	n_rotate = 0;
	half = n / 2 + n % 2;
	median = ft_findmedian(*pile, BPILE, n);
	while (n_push < half)
	{
		if (pile->b->n > median)
		{
			pile = ft_add_ope(sol, pile, PA);
			n_push++;
		}
		else
		{
			pile = ft_add_ope(sol, pile, NRB);
			n_rotate++;
		}
		if (pile == NULL)
			return (NULL);
	}
	while (n_rotate-- > 0)
	{
		if (!(pile = ft_add_ope(sol, pile, RRB)))
			return (NULL);
	}
	return (pile);
}

t_pile *ft_push_half(t_pile *pile, t_dope *sol, int pd, int n)
{
	if (pd == APILE)
		return (ft_push_half2b(pile, sol, n));
	else
		return (ft_push_half2a(pile, sol, n));
}
