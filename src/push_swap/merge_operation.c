#include "push_swap.h"

static bool	is_r_combo(t_op op, t_op next)
{
	if ((op == ra && next == rb) || (op == rb && next == ra))
		return (true);
	return (false);
}

static bool	is_rr_combo(t_op op, t_op next)
{
	if ((op == rra && next == rrb) || (op == rrb && next == rra))
		return (true);
	return (false);
}

static bool	is_able_delete(t_op op, t_op next)
{
	if ((op == pa && next == pb) || (op == pb && next == pa))
		return (true);
	return (false);
}

static bool	is_possible_to_short(t_ps *ps)
{
	int	i;

	i = 0;
	while (ps->ans != NULL && ps->ans[i] != err && ps->ans[i + 1] != err)
	{
		if (is_r_combo(ps->ans[i], ps->ans[i + 1]))
			return (true);
		if (is_rr_combo(ps->ans[i], ps->ans[i + 1]))
			return (true);
		if (is_able_delete(ps->ans[i], ps->ans[i + 1]))
			return (true);
		i++;
	}
	return (false);
}

bool	merge_operation(t_ps *ps)
{
	int	i;

	if (!is_possible_to_short(ps))
		return (true);
	i = 0;
	while (ps->ans != NULL && ps->ans[i] != err && ps->ans[i + 1] != err)
	{
		if (is_r_combo(ps->ans[i], ps->ans[i + 1]))
			ps->ans = convert_rr(ps->ans, i);
		else if (is_rr_combo(ps->ans[i], ps->ans[i + 1]))
			ps->ans = convert_rrr(ps->ans, i);
		else if (is_able_delete(ps->ans[i], ps->ans[i + 1]))
		{
			ps->ans = delete_pp(ps->ans, i);
			continue ;
		}
		i++;
	}
	if (ps->ans == NULL)
		return (false);
	return (merge_operation(ps));
}
