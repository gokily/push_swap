/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:17:20 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 17:34:13 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_operation.h"

int		ft_sort_end(t_pile *pile, t_dope *sol, int pd, int n)
{
	printf("#In ft_sort_end, pd is %d and n is %d\n", pd, n);
	print_pile(*pile);
	if (n == 1)
	{
		if (pd == BPILE)
			pile = ft_add_ope(sol, pile, PA);
		return (pile == NULL ? 0 : 1);
	}
	if (pd == APILE)
	{
		if (pile->a->n > pile->a->next->n)
			pile = ft_add_ope(sol, pile, SA);
		return (pile == NULL ? 0 : 1);
	}
	else
	{
		if (pile->b->n < pile->b->next->n)
			pile = ft_add_ope(sol, pile, SB);
		if (pile == NULL || ft_add_ope(sol, pile, PA) == NULL ||
				ft_add_ope(sol, pile, PA) == NULL)
			return (0);
		return (1);
	}
}

int		ft_sort_pile(t_pile *pile, t_dope *sol, int pd, int n)
{
	int		i;

	i = 0;
	if (n <= 2)
		return (ft_sort_end(pile, sol, pd, n));
	if (!ft_push_half(pile, sol, pd, n) ||
			!ft_sort_pile(pile, sol, APILE, n / 2 + n % 2))
		return (0);
	return (ft_sort_pile(pile, sol, BPILE, n / 2));
}

t_dope	*ft_get_solution(t_pile *pile, int n)
{
	t_dope	*sol;
	t_lope	*first;

	if (!(first = malloc(sizeof(t_lope))))
		return (NULL);
	if (!(sol = malloc(sizeof(t_dope))))
	{
		free(first);
		return (NULL);
	}
	first->next = NULL;
	first->id = 55;
	sol->head = first;
	sol->tail = first;
	if (!(ft_sort_pile(pile, sol, APILE, n)))
		return (NULL);
	return (sol);
}
