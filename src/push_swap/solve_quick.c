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
			ps->ans = record_do(ra, ps);
			(ps->i)++;
		}
		else if (j + 2 != end && (*ps->a)->next->val == ps->list[ps->i]
			&& (*ps->a)->val == ps->list[ps->i + 1])
		{
			ps->ans = record_do(sa, ps);
			continue ;
		}
		else
			ps->ans = record_do(pb, ps);
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
			ps->ans = record_do(pa, ps);
		else if ((*ps->b)->val == ps->list[ps->i])
		{
			ps->ans = record_do(pa, ps);
			ps->ans = record_do(ra, ps);
			(ps->i)++;
		}
		else
		// choose rb or rrb
			ps->ans = record_do(rb, ps);
		j++;
	}
	sort_first_half(ps, start, start + m);
	sort_second_half(ps, end);
}

static void	set_first(t_ps *ps, int size)
{
	t_op	dir;
	int		i;

	dir = set_dir(ps, size);
	i = 0;
	while (i < size)
	{
		if (((*ps->a)->val <= ps->list[size - 1]))
		{
			ps->ans = record_do(pb, ps);
			i++;
		}
		else
			ps->ans = record_do(dir, ps);
	}
}

t_op	*solve_quick(t_ps *ps)
{
	int	size;
	int	i;

	ps->list = sort_list(ps->a, ps->list);
	ps->list_len = get_stacklen(ps->a);
	size = ps->list_len / 2;
	set_first(ps, size);
	sort_first_half(ps, 0, size);
	i = size;
	while (i < ps->list_len)
	{
		ps->ans = record_do(pb, ps);
		i++;
	}
	sort_first_half(ps, size, ps->list_len);
	return (ps->ans);
}
