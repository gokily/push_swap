/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:40:48 by gly               #+#    #+#             */
/*   Updated: 2019/03/21 16:53:57 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_int_array(const char *str)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = str[i] == '-' ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nb *= 10;
		nb += str[i] - 48;
		if ((sign == 1 && nb > INT_MAX) || (sign == -1 && nb < INT_MIN))
			return (0);
		i++;
	}
	nb *= sign;
	return (1);
}

static int	ft_check_double(t_lnum *lst)
{
	t_lnum	*other;

	if (lst == NULL)
		return (1);
	while (lst->next != NULL)
	{
		other = lst->next;
		while (other != NULL)
		{
			if (lst->n == other->n)
				return (1);
			other = other->next;
		}
		lst = lst->next;
	}
	return (0);
}

t_lnum		*ft_read_arg(int ac, char **av)
{
	int		i;
	int		n;
	t_lnum	*lst;
	t_lnum	*elem;
	char	**tab;

	i = 1;
	lst = NULL;
	while (i < ac)
	{
		tab = ft_strsplit(av[i], ' ');
		n = 0;
		while (tab[n] != 0)
		{
			if (!ft_int_array(tab[n]) || !(elem = ft_lnum_new(ft_atoi(tab[n]))))
				ft_free_exit(lst);
			ft_addback_lnum(&lst, elem);
			n++;
		}
		ft_free_strtab(tab);
		i++;
	}
	if (ft_check_double(lst) == 1)
		ft_free_exit(lst);
	return (lst);
}
