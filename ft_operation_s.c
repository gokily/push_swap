/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:43:16 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 16:43:44 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_sa(t_pile *pile)
{
	ft_lnum_swap_top(pile->a);
	return (pile);
}

t_pile	*ft_sb(t_pile *pile)
{
	ft_lnum_swap_top(pile->b);
	return (pile);
}

t_pile	*ft_ss(t_pile *pile)
{
	ft_lnum_swap_top(pile->a);
	ft_lnum_swap_top(pile->b);
	return (pile);
}
