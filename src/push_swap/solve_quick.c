#include "push_swap.h"

static void	sort_first_half(t_ps *ps, int start, int end);

static void	sort_second_half(t_ps *ps, int end)
{
	int	j;

	if (ps->i >= end)
		return ;
	j = ps->i;
	while (j < end && ps->i != end)
	{
		if ((*ps->a)->val == ps->list[ps->i])
		{
			ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
			(ps->i)++;
		}
		else if (j + 2 != end && (*ps->a)->next->val == ps->list[ps->i]
			&& (*ps->a)->val == ps->list[ps->i + 1])
		{
			ps->ans = record_do(sa, ps->ans, ps->a, ps->b);
			continue ;
		}
		else
			ps->ans = record_do(pb, ps->ans, ps->a, ps->b);
		j++;
	}
	if (ps->i < end)
		sort_first_half(ps, ps->i, end);
}

static void	sort_first_half(t_ps *ps, int start, int end)
{
	int	j;
	int	m;

	if (*ps->b == NULL || ps->i >= end || start > end)
		return ;
	m = (end - start) / 2;
	j = start;
	while (*ps->b != NULL && j < end)
	{
		if ((*ps->b)->val >= ps->list[start + m])
			ps->ans = record_do(pa, ps->ans, ps->a, ps->b);
		else if ((*ps->b)->val == ps->list[ps->i])
		{
			ps->ans = record_do(pa, ps->ans, ps->a, ps->b);
			ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
			(ps->i)++;
		}
		else
			ps->ans = record_do(rb, ps->ans, ps->a, ps->b);
		j++;
	}
	sort_first_half(ps, start, start + m);
	sort_second_half(ps, end);
}

static void	set_tmp(t_ps *ps, int i, int end)
{
	while (i < end)
	{
		if (((*ps->a)->val <= ps->list[end - 1]))
		{
			ps->ans = record_do(pb, ps->ans, ps->a, ps->b);
			i++;
		}
		else
			ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
	}
}

char	**solve_quick(t_ps *ps)
{
	int	size;

	ps->list = sort_list(ps->a, ps->list);
	ps->list_len = get_stacklen(ps->a);
	size = ps->list_len / 2;
	set_tmp(ps, 0, size);
	sort_first_half(ps, 0, size);
	set_tmp(ps, size, ps->list_len);
	sort_first_half(ps, size, ps->list_len);
	return (ps->ans);
}