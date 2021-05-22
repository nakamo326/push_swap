#include "push_swap.h"

bool	is_possible_to_short(t_ps *ps)
{
	int	i;

	i = 0;
	while (ps->ans != NULL && ps->ans[i + 1] != NULL)
	{
		if (is_able_merge(ps->ans[i], ps->ans[i + 1]))
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
	while (ps->ans != NULL && ps->ans[i + 1] != NULL)
	{
		if (is_able_merge(ps->ans[i], ps->ans[i + 1]))
			ps->ans = convert_rr(ps->ans, i);
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
