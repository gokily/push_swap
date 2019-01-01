#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"

#include <stdio.h>

typedef struct		s_lnum
{
	struct s_lnum	*next;
	int				n;
}					t_lnum;

typedef struct		s_pile
{
	t_lnum			*a;
	t_lnum			*b;
}					t_pile;

int					ft_int_array(const char *str);

t_lnum				*ft_lnum_new(int n);
void				ft_lnum_swap_top(t_lnum	*lst);
void				ft_lnum_rotate(t_lnum **lst);
void				ft_lnum_rrotate(t_lnum **lst);
void				ft_addback_lnum(t_lnum **lst, t_lnum *elem);
int					ft_lnum_is_sort(t_lnum *lst);
void				ft_lnum_delall(t_lnum *lst);

int					ft_checkpile(t_pile pile);
void				ft_free_pile(t_pile pile);

int					ft_error(int i);


#endif