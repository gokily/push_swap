
CHECKER	=	checker

PUSH_SWAP	=	push_swap

SRC	=	ft_checker.c	\
		ft_pile_manipulators.c	\
		ft_error.c	\
		ft_lnum_manipulators.c	\
		ft_operation.c	\
		ft_operation_s.c	\
		ft_operation_p.c	\
		ft_operation_r.c	\
		ft_operation_rr.c	\

CC	=	gcc

#CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address
CFLAGS	=	-Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

CHECKER_O	=	ft_checker.o	\
		ft_pile_manipulators.o	\
		ft_error.o	\
		ft_lnum_manipulators.o	\
		ft_operation.o	\
		ft_operation_s.o	\
		ft_operation_p.o	\
		ft_operation_r.o	\
		ft_operation_rr.o	\

LIBFT	=	libft/libft.a

LIBFTFLAG	=	-lft -L libft

all: $(LIBFT) $(CHECKER) $(PUSH_SWAP)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(CHECKER): $(CHECKER_O)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_O) $(LIBFTFLAG)

$(PUSH_SWAP):
	echo "Not yet"

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