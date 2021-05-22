#include "push_swap.h"

static void	sort_first_half(t_ps *ps, int start, int end);

static void	sort_second_half(t_ps *ps, int end)
{
	int	j;

	if (ps->index >= end)
		return ;
	j = ps->index;
	while (j < end && ps->index != end)
	{
		if ((*ps->a)->val == ps->list[ps->index])
		{
			ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
			(ps->index)++;
		}
		else if (j + 2 != end && (*ps->a)->next->val == ps->list[ps->index]
			&& (*ps->a)->val == ps->list[ps->index + 1])
		{
			ps->ans = record_do(sa, ps->ans, ps->a, ps->b);
			continue ;
		}
		else
			ps->ans = record_do(pb, ps->ans, ps->a, ps->b);
		j++;
	}
	if (ps->index < end)
		sort_first_half(ps, ps->index, end);
}

static void	sort_first_half(t_ps *ps, int start, int end)
{
	int	j;
	int	m;

	if (*ps->b == NULL || ps->index >= end || start > end)
		return ;
	m = (end - start) / 2;
	j = start;
	while (*ps->b != NULL && j < end)
	{
		if ((*ps->b)->val >= ps->list[start + m])
			ps->ans = record_do(pa, ps->ans, ps->a, ps->b);
		else if ((*ps->b)->val == ps->list[ps->index])
		{
			ps->ans = record_do(pa, ps->ans, ps->a, ps->b);
			ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
			(ps->index)++;
		}
		else
			ps->ans = record_do(rb, ps->ans, ps->a, ps->b);
		j++;
	}
	sort_first_half(ps, start, start + m);
	sort_second_half(ps, end);
}

static void	set_tmp(t_ps *ps, int start, int end)
{
	t_stack	*s;
	int		i;

	s = *ps->a;
	i = start;
	while (i < end)
	{
		if ((s->val <= ps->list[end - 1]))
		{
			ps->ans = record_do(pb, ps->ans, &s, ps->b);
			i++;
		}
		else
			ps->ans = record_do(ra, ps->ans, &s, ps->b);
	}
	*ps->a = s;
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
