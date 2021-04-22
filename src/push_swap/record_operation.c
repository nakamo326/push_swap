#include "push_swap.h"

static char	*convert_op(t_op op)
{
	static char	str_set[][4] = {
		"err", "sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"
	};

	return (str_set[op]);
}

char	**record_do(t_op op, char **ans, t_stack **a_top, t_stack **b_top)
{
	char	*str;

	str = convert_op(op);
	ans = ft_addstr_split(ans, str);
	if (ans == NULL)
		return (NULL);
	do_operation(str, a_top, b_top);
	return (ans);
}
