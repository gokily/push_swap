/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:42:36 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 16:43:08 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_rra(t_pile *pile)
{
	ft_lnum_rrotate(&pile->a);
	return (pile);
}

t_pile	*ft_rrb(t_pile *pile)
{
	ft_lnum_rrotate(&pile->b);
	return (pile);
}

t_pile	*ft_rrr(t_pile *pile)
{
	ft_lnum_rrotate(&pile->a);
	ft_lnum_rrotate(&pile->b);
	return (pile);
}
