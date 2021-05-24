#include "push_swap.h"

bool	is_able_merge(t_op op, t_op next)
{
	if ((op == ra && next == rb) || (op == rb && next == ra))
		return (true);
	return (false);
}

bool	is_able_delete(t_op op, t_op next)
{
	if ((op == pa && next == pb) || (op == pb && next == pa))
		return (true);
	return (false);
}

t_op	*convert_rr(t_op *ans, int i)
{
	ans[i] = rr;
	i++;
	while (ans[i + 1] != err)
	{
		ans[i] = ans[i + 1];
		i++;
	}
	ans[i] = err;
	return (ans);
}

t_op	*delete_pp(t_op *ans, int i)
{
	while (ans[i + 2] != err)
	{
		ans[i] = ans[i + 2];
		ans[i + 2] = err;
		i++;
	}
	ans[i] = err;
	return (ans);
}
