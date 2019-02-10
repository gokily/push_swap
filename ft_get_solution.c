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

int		ft_sort_pile(t_pile *pile, t_dope *sol, int pd, int n)
{
	if (ft_pile_is_sorted(pile, sol))
		return (1);
	if (n <= 5)
	{
		if (n == 2)
			pile = ft_add_ope(sol, pile, SA);
		else
			pile = ft_sort_end(pile, sol, pd, n);
		return (pile == NULL ? 0 : 1);
	}
	if (!ft_push_half2pd(pile, sol, -pd, n) ||
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
	first->id = 999;
	sol->head = first;
	sol->tail = first;
	if (!(ft_sort_pile(pile, sol, APILE, n)))
		return (NULL);
	return (sol);
}
