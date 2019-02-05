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

typedef struct		s_lope
{
	struct s_lope	*next;
	int				id;
}					t_lope;

typedef struct		s_dope
{
	t_lope			*head;
	t_lope			*tail;
}					t_dope;

int					ft_int_array(const char *str);

t_lnum  *ft_read_arg(int ac, char **av);
int     ft_validarg(int ac, char **av);

t_lnum				*ft_lnum_new(int n);
void				ft_lnum_swap_top(t_lnum	*lst);
void				ft_lnum_rotate(t_lnum **lst);
void				ft_lnum_rrotate(t_lnum **lst);
void				ft_addback_lnum(t_lnum **lst, t_lnum *elem);
int					ft_lnum_is_sort(t_lnum *lst);
void				ft_lnum_delall(t_lnum *lst);

int					ft_checkpile(t_pile pile);
void				ft_free_pile(t_pile pile);
int    				ps_next_line(const int fd, char **line);
int					ft_error(int i);

t_dope  *ft_get_solution(t_pile *pile, int n);
void    ft_print_solution(t_dope *sol);

t_pile	*ft_push_half2pd(t_pile *pile, t_dope *sol, int pd, int n);

int		ft_pile_is_sorted(t_pile *pile, t_dope *sol);

t_pile *ft_sort_end(t_pile *pile, t_dope *sol, int pd, int n);
t_pile  *ft_sort_three(t_pile *pile, t_dope *sol, int pd, int flag);

// These functions need to be included in the libft
void	ft_sort_inttab(int *tab, int n);
int   ft_int_is_bigger(int first, int second);
int   ft_int_is_smaller(int first, int second);

// Debug function
void    print_pile(t_pile pile);
#endif
