/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:40:52 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 16:41:46 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_ra(t_pile *pile)
{
	ft_lnum_rotate(&pile->a);
	return (pile);
}

t_pile	*ft_rb(t_pile *pile)
{
	ft_lnum_rotate(&pile->b);
	return (pile);
}

t_pile	*ft_rr(t_pile *pile)
{
	ft_lnum_rotate(&pile->a);
	ft_lnum_rotate(&pile->b);
	return (pile);
}
