/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:40:30 by gly               #+#    #+#             */
/*   Updated: 2019/02/21 11:25:15 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_operation.h"

t_pile	ft_read_and_do_ope(t_pile pile)
{
	char	*line;
	int		ret;
	t_opp	*tab;

	tab = ft_define_ope();
	while ((ret = ps_next_line(0, &line)))
	{
		if (ret == -1)
			ft_error(2);
		if (ft_validope(line) == 0)
		{
			free(tab);
			ft_free_pile(pile);
			ft_error(2);
		}
		ft_doope(&pile, line, tab);
		free(line);
	}
	free(tab);
	return (pile);
}

int		main(int ac, char **av)
{
	t_lnum	*lst;
	t_pile	pile;

	if (ac == 1 || ft_validarg(ac, av) == 0)
		ft_error(1);
	if (!(lst = ft_read_arg(ac, av)))
		ft_error(1);
	pile.a = lst;
	pile.b = NULL;
	pile = ft_read_and_do_ope(pile);
	if (ft_checkpile(pile))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_free_pile(pile);
	return (0);
}
