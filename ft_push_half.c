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
	printf("n is %d and median is %d\n", n, median);
	return (median);
}

t_pile	*ft_push_half2b(t_pile *pile, t_dope *sol, int n)
{
	int		i;
	int		median;
	int		half;

	i = 0;
	printf("\nIn push half 2 b, n is %d\n", n);
	print_pile(*pile);
	median = ft_findmedian(*pile, APILE, n);
	while (i++ < n)
	{
		if (pile->a->n <= median)
		{
			printf("Moving %d to pile B\n", pile->a->n);
			pile = ft_add_ope(sol, pile, PB);
		}
		else
			pile = ft_add_ope(sol, pile, NRA);
		if (pile == NULL)
			return (NULL);
	}
	i = 0;
	half = n / 2 + n % 2;
	while (i++ < half)
	{
		if (!(pile = ft_add_ope(sol, pile, RRA)))
			return (NULL);
	}
	return (pile);
}

t_pile	*ft_push_half2a(t_pile *pile, t_dope *sol, int n)
{
	int		i;
	int		median;
	int		half;

	i = 0;
	printf("\nIn push half 2 a, n is %d\n", n);
	print_pile(*pile);

	median = ft_findmedian(*pile, BPILE, n);
	while (i++ < n)
	{
		if (pile->b->n > median)
		{
			printf("Moving %d to pile A\n", pile->b->n);
			pile = ft_add_ope(sol, pile, PA);
		}
		else
			pile = ft_add_ope(sol, pile, NRB);
		if (pile == NULL)
			return (NULL);
	}
	i = 0;
	half = n / 2;
	while (i++ < half)
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
