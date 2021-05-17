#include "push_swap.h"

bool	is_range(int val, int start, int end)
{
	return (val >= start && val <= end);
}

bool	set_tmp(t_ps *ps, int start, int end)
{
	int		i;
	int		r;

	i = start;
	r = 0;
	while(i < end)
	{
		if (is_range((*ps->a)->val, ps->list[start], ps->list[end - 1]))
		{
			ps->ans = record_do(pb, ps->ans, ps->a, ps->b);
			i++;
			continue ;
		}
		ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
		r++;
	}
	while (start != 0 && r > 0)
	{
		ps->ans = record_do(rra, ps->ans, ps->a, ps->b);
		r--;
	}
	return (true);
}