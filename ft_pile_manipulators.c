/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_manipulators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:33:50 by gly               #+#    #+#             */
/*   Updated: 2019/03/21 09:40:55 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_operation.h"

int		ft_length_stack(t_pile *pile, int pd)
{
	int		length;
	t_lnum	*stack;

	length = 0;
	stack = pd == APILE ? pile->a : pile->b;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

void	ft_free_pile(t_pile pile)
{
	if (pile.a != NULL)
		ft_lnum_delall(pile.a);
	if (pile.b != NULL)
		ft_lnum_delall(pile.b);
	return ;
}

int		ft_checkpile(t_pile pile)
{
	if (pile.b != NULL)
		return (0);
	return (ft_lnum_is_sort(pile.a));
}
