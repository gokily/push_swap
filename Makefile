
CHECKER	=	checker

PUSH_SWAP	=	push_swap

SRC	=	ft_checker.c	\
		ft_pile_manipulators.c	\
		ft_error.c	\
		ft_lnum_manipulators.c	\
		ft_operation.c	\

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

OBJ = $(SRC:.c=.o)

CHECKER_O	=	ft_checker.o	\
		ft_checkpile.o	\
		ft_error.o	\
		ft_lnum_manipulators.o	\
		ft_operation.c	\

all: $(CHECKER) $(PUSH_SWAP)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(CHECKER): $(CHECKER_O)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_O)

$(PUSH_SWAP):
	echo "Not yet"

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(CHECKER) $(PUSH_SWAP)

re: fclean all

.PHONY: clean fclean re all