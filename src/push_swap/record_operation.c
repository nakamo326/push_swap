#include "push_swap.h"

static bool	extend_answer(t_ps *ps)
{
	int		new_size;
	t_op	*new_ans;
	int		i;

	new_size = ps->ans_size * 2;
	new_ans = malloc(sizeof(t_op) * new_size);
	if (new_ans == NULL)
		return (false);
	i = 0;
	while (ps->ans[i] != err)
	{
		new_ans[i] = ps->ans[i];
		i++;
	}
	new_ans[i] = err;
	free(ps->ans);
	ps->ans = new_ans;
	return (true);
}

static bool	add_answer(t_ps *ps, t_op op)
{
	int	i;

	i = 0;
	while (ps->ans[i] != err)
		i++;
	ps->ans[i] = op;
	ps->ans[i + 1] = err;
	if (i + 1 == ps->ans_size)
		if (!extend_answer(ps))
			return (false);
	return (true);
}

t_op	*record_do(t_op op, t_ps *ps)
{
	char	*str;

	str = convert_op(op);
	if (!add_answer(ps, op))
		return (NULL);
	do_operation(str, ps->a, ps->b);
	return (ps->ans);
}
