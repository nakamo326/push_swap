#include "push_swap.h"

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
		else if (ps->ans[i + 2] != err && ps->ans[i + 3] != err
			&& is_spps_combo(ps->ans, i))
			ps->ans = merge_spps(ps->ans, &i);
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
