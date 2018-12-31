#include "push_swap.h"
#include "ps_operation.h"

int			ft_validope(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (1);
	else if (ft_strcmp(line, "sb") == 0)
		return (1);
	else if (ft_strcmp(line, "ss") == 0)
		return (1);
	else if (ft_strcmp(line, "pa") == 0)
		return (1);
	else if (ft_strcmp(line, "pb") == 0)
		return (1);
	else if (ft_strcmp(line, "sb") == 0)
		return (1);
	else if (ft_strcmp(line, "ra") == 0)
		return (1);
	else if (ft_strcmp(line, "rb") == 0)
		return (1);
	else if (ft_strcmp(line, "rr") == 0)
		return (1);
	else if (ft_strcmp(line, "rra") == 0)
		return (1);
	else if (ft_strcmp(line, "rrb") == 0)
		return (1);
	else if (ft_strcmp(line, "rrr") == 0)
		return (1);
	return (0);
}

t_opp	*ft_define_ope(void)
{
	t_opp	tab[12];

	tab[0] = {.type = "sa", .ope = &ft_ope_sa};
	tab[1] = {.type = "sa", .ope = &ft_ope_sa};
	tab[2] = {.type = "sa", .ope = &ft_ope_sa};
	tab[3] = {.type = "sa", .ope = &ft_ope_sa};
	tab[4] = {.type = "sa", .ope = &ft_ope_sa};
	tab[5] = {.type = "sa", .ope = &ft_ope_sa};
	tab[6] = {.type = "sa", .ope = &ft_ope_sa};
	tab[7] = {.type = "sa", .ope = &ft_ope_sa};
	tab[8] = {.type = "sa", .ope = &ft_ope_sa};
	tab[9] = {.type = "sa", .ope = &ft_ope_sa};
	tab[10] = {.type = "sa", .ope = &ft_ope_sa};
	tab[11] = {.type = "sa", .ope = &ft_ope_sa};
	tab[12] = {.type = "sa", .ope = &ft_ope_sa};
	return (tab);
}

t_pile	ft_doope(t_pile pile, char *line, t_opp *tab)
{
	int		i;

	i = 0;
	while (i < 12)
	{
		if (ft_strcmp(line, tab[i].type) == 0)
			return (tab[i].ope(pile));
		i++;
	}
	return (pile);
}