/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_manipulators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:33:50 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 16:33:52 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
