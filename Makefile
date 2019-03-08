
CHECKER	=	checker

PUSH_SWAP	=	push_swap

SRC	=	ft_checker.c	\
		ft_pile_manipulators.c	\
		ft_error.c	\
		ft_lnum_manipulators.c	\
		ft_lnum_manipulators2.c	\
		ft_operation.c	\
		ft_operation_s.c	\
		ft_operation_p.c	\
		ft_operation_r.c	\
		ft_operation_rr.c	\
		ps_next_line.c	\
		ft_parse_arg.c	\
		ft_print_solution.c	\
		ft_get_solution.c	\
		ft_push_half.c	\
		ft_pushswap.c	\
		ft_pile_is_sorted.c	\
		ft_sort_end.c	\
		ft_sort_three.c	\

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g
#CFLAGS	=	-Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

CHECKER_O	=	ft_checker.o	\
				ft_pile_manipulators.o	\
				ft_error.o	\
				ft_lnum_manipulators.o	\
				ft_lnum_manipulators2.o	\
				ft_operation.o	\
				ft_operation_s.o	\
				ft_operation_p.o	\
				ft_operation_r.o	\
				ft_operation_rr.o	\
				ps_next_line.o	\
				ft_parse_arg.o	\

PUSHSWAP_O	=	ft_get_solution.o	\
				ft_error.o	\
				ft_lnum_manipulators.o	\
				ft_lnum_manipulators2.o	\
				ft_operation.o	\
				ft_operation_s.o	\
				ft_operation_p.o	\
				ft_operation_r.o	\
				ft_operation_rr.o	\
				ft_pile_manipulators.o	\
				ft_push_half.o	\
				ft_pushswap.o	\
				ft_parse_arg.o	\
				ft_print_solution.o	\
				ft_pile_is_sorted.o	\
				ft_sort_end.o	\
				ft_sort_three.o	\

LIBFT	=	libft/libft.a

LIBFTFLAG	=	-lft -L libft

all: $(LIBFT) $(CHECKER) $(PUSH_SWAP)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(CHECKER): $(CHECKER_O)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_O) $(LIBFTFLAG) print_pile.c

$(PUSH_SWAP): $(PUSHSWAP_O)
	$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(PUSHSWAP_O) $(LIBFTFLAG) ft_sort_inttab.c ft_int_comparators.c print_pile.c

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(LIBFT)
	/bin/rm -f $(CHECKER) $(PUSH_SWAP)

re: fclean all

.PHONY: clean fclean re all
