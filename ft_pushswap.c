/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:04:52 by gly               #+#    #+#             */
/*   Updated: 2019/03/21 16:42:02 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_lnum	*lst;
	t_pile	pile;
	t_dope	*sol;

	if (ac == 1)
		return (1);
	if (!(lst = ft_read_arg(ac, av)))
		ft_error(1);
	pile.a = lst;
	pile.b = NULL;
	sol = ft_get_solution(&pile, ft_lnum_length(lst));
	ft_print_solution(sol);
	ft_free_t_dope(sol);
	ft_free_pile(pile);
	return (1);
}
