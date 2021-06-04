#include "push_swap.h"

bool	is_r_combo(t_op op, t_op next)
{
	if ((op == ra && next == rb) || (op == rb && next == ra))
		return (true);
	return (false);
}

bool	is_rr_combo(t_op op, t_op next)
{
	if ((op == rra && next == rrb) || (op == rrb && next == rra))
		return (true);
	return (false);
}

bool	is_able_delete(t_op op, t_op next)
{
	if ((op == pa && next == pb) || (op == pb && next == pa))
		return (true);
	return (false);
}

bool	is_spps_combo(t_op *ans, int i)
{
	if (ans[i] == sa && ans[i + 1] == pb
		&& ans[i + 2] == pb && ans[i + 3] == sa)
		return (true);
	if (ans[i] == sa && ans[i + 1] == pb
		&& ans[i + 2] == pb && ans[i + 3] == sb)
		return (true);
	return (false);
}
