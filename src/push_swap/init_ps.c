#include "push_swap.h"

t_ps	*init_ps(void)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (ps == NULL)
		exit(EXIT_FAILURE);
	ps->a = malloc(sizeof(t_stack *));
	if (ps->a == NULL)
	{
		free(ps);
		exit(EXIT_FAILURE);
	}
	*(ps->a) = NULL;
	ps->b = malloc(sizeof(t_stack *));
	if (ps->b == NULL)
	{
		free(ps->a);
		free(ps);
		exit(EXIT_FAILURE);
	}
	*(ps->b) = NULL;
	ps->list = NULL;
	ps->ans = NULL;
	return (ps);
}
