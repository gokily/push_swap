/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:40:30 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 15:46:26 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_operation.h"

 int		main(int ac, char **av)
{
	t_lnum	*lst;
	char	*line;
	int		ret;
	t_pile	pile;
	t_opp	*tab;

	if (ac == 1 || ft_validarg(ac, av) == 0)
		return (ft_error(1));
	if (!(lst = ft_read_arg(ac, av)))
		return (ft_error(1));
	pile.a = lst;
	pile.b = NULL;
	tab = ft_define_ope();
	while ((ret = ps_next_line(0, &line)))
	{
		if (ret == -1)
			return (ft_error(2));
		if (ft_validope(line) == 0)
		{
			free(tab);
			ft_free_pile(pile);
			return (ft_error(2));
		}
		ft_doope(&pile, line, tab);
		free(line);
	}
	if (ft_checkpile(pile))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_free_pile(pile);
	free(tab);
	return (0);
}
