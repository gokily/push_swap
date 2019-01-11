/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:34:55 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 15:38:20 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_operation.h"

void	ft_print_solution(t_dope *sol)
{
	t_lope	*elem;
	t_opp	*opptab;

	elem = sol->head->next;
	opptab = ft_define_ope();
	while (elem != NULL)
	{
		ft_putendl(opptab[elem->id].type);
		elem = elem->next;
	}
}
