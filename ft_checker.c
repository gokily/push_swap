#include "push_swap.h"
#include "ps_operation.h"

int		ft_int_array(const char *str)
{
	int		i;
	long 	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = str[i] == '-' ? -1 : 1;
	if (ft_strlen(str) > 11)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
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
	while ((ret = get_next_line(1, &line)))
	{
		if (ft_validope(line) == 0)
		{
			free(tab);
			ft_free_pile(pile);
			return (ft_error(2));
		}
		pile = ft_doope(pile, line, tab);
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
