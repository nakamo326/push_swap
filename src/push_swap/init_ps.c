#include "push_swap.h"

t_ps	*init_ps(void)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	ps->a = malloc(sizeof(t_stack *));
	ps->b = malloc(sizeof(t_stack *));
	ps->ans = malloc(sizeof(t_op) * 2048);
	if (!ps || !ps->a || !ps->b || !ps->ans)
	{
		free(ps->a);
		free(ps);
		exit(EXIT_FAILURE);
	}
	*(ps->a) = NULL;
	*(ps->b) = NULL;
	ps->ans[0] = err;
	ps->list = NULL;
	ps->i = 0;
	ps->ans_size = 2048;
	return (ps);
}
