#include "push_swap.h"

static char	*convert_op(t_op op)
{
	static char	str_set[][4] = {
		"err", "sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"
	};

	return (str_set[op]);
}

static bool add_answer(t_op *ans, t_op op)
{
	int	i;

	i = 0;
	while (ans[i] != err)
		i++;
	ans[i] = op;
	ans[i + 1] = err;
	//size extension
	return (true);
}

t_op	*record_do(t_op op, t_op *ans, t_stack **a, t_stack **b)
{
	char	*str;

	str = convert_op(op);
	if (!add_answer(ans, op))
		return (NULL);
	do_operation(str, a, b);
	return (ans);
}
