#include "push_swap.h"
#include <stdlib.h>

t_lnum	*ft_lnum_new(int n)
{
	t_lnum	*elem;

	if (!(elem = malloc(sizeof(t_lnum))))
		return (NULL);
	elem->next = NULL;
	elem->n = n;
	return (elem);
}

void	ft_addback_lnum(t_lnum **lst, t_lnum *elem)
{
	t_lnum	*last;

	if (*lst == NULL)
	{
		*lst = elem;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = elem;
	return ;
}

int		ft_lnum_is_sort(t_lnum *lst)
{
	int	i;

	if (lst->next == NULL)
		return (1);
	while (lst->next->next != NULL)
	{
		if (lst->n > lst->next->n)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_lnum_delall(t_lnum *lst)
{
	t_lnum	*tmp;

	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return ;
}