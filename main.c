#include "push_swap.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char test[] = "2123123123";

	printf("size of long is: %d\n", INT_MAX);
	printf("size of int is: %d\n", sizeof(int));
	if (ft_int_array(test) == 1)
		printf("%s is an integer\n", test);
	else
		printf("%s is not an integer\n", test);
	if (ac >= 2)
	{
		if (ft_int_array(av[1]) == 1)
			printf("%s is an integer\n", av[1]);
		else
			printf("%s is not an integer\n", av[1]);
		return (1);
	}	
}