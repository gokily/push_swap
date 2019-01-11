#include "push_swap.h"

void	print_pile(t_pile pile)
{
	if (pile.a != NULL)
	{
		puts("Pile A is not null and contains:");
		while (pile.a != NULL)
		{
			printf("%d ",pile.a->n);
			pile.a = pile.a->next;
		}
		puts("\n");
	}
	if (pile.b != NULL)
	{
		puts("Pile B is not null and contains:");
		while (pile.b != NULL)
		{
			printf("%d ",pile.b->n);
			pile.b = pile.b->next;
		}
		puts("\n");
	}
}
