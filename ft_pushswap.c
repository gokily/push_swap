/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:04:52 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 15:39:08 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_lnum	*lst;
	t_pile	pile;

	if (ac == 1 || ft_validarg(ac, av) == 0)
		return (ft_error(1));
	if (!(lst = ft_read_arg(ac, av)))
		return (ft_error(1));
	pile.a = lst;
	pile.b = NULL;
	ft_print_solution(ft_get_solution(&pile, ac - 1));
	return (1);
}