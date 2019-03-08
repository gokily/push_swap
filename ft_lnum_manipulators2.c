/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnum_manipulators2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:05:21 by gly               #+#    #+#             */
/*   Updated: 2019/02/21 12:05:34 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lnum_swap_top(t_lnum *lst)
{
	int		tmp;

	if (lst != NULL && lst->next != NULL)
	{
		tmp = lst->n;
		lst->n = lst->next->n;
		lst->next->n = tmp;
	}
	return ;
}

void	ft_lnum_rotate(t_lnum **lst)
{
	t_lnum	*tmp;

	tmp = *lst;
	if (tmp != NULL && tmp->next != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *lst;
		*lst = (*lst)->next;
		tmp->next->next = NULL;
	}
	return ;
}

void	ft_lnum_rrotate(t_lnum **lst)
{
	t_lnum	*tmp;

	tmp = *lst;
	if (tmp != NULL && tmp->next != NULL)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = *lst;
		*lst = tmp->next;
		tmp->next = NULL;
	}
	return ;
}
