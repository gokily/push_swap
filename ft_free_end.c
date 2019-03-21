/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 09:29:12 by gly               #+#    #+#             */
/*   Updated: 2019/03/21 09:41:47 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_free_t_dope(t_dope *sol)
{
	t_lope	*elem;
	t_lope	*next;

	if (sol == NULL)
		return (1);
	elem = sol->head;
	while (elem != NULL)
	{
		next = elem->next;
		free(elem);
		elem = NULL;
		elem = next;
	}
	free(sol);
	sol = NULL;
	return (1);
}
