/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:40:48 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 15:43:52 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_int_array(const char *str)
{
	int		i;
	long 	long nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = str[i] == '-' ? -1 : 1;
	if (ft_strlen(str) > 11)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	nb *= sign;
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}

int		ft_validarg(int ac, char **av)
{
	int			i;
	int			j;

	i = 1;
	while (i < ac)
	{
		if (ft_int_array(av[i]) == 0)
			return (0);
		i++;
	}
	i = 1;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_lnum	*ft_read_arg(int ac, char **av)
{
	int		i;
	t_lnum	*lst;
	t_lnum	*elem;

	i = 1;
	lst = NULL;
	while (i < ac)
	{
		if (!(elem = ft_lnum_new(ft_atoi(av[i]))))
			return (NULL);
		ft_addback_lnum(&lst, elem);
		i++;
	}
	return (lst);
}
