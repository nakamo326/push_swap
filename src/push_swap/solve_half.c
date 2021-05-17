#include "push_swap.h"

int	check_toptwo(t_ps *ps, int i)
{
	if (*ps->a == NULL || i >= ps->list_len)
		return (i);
	if ((*ps->a)->val == ps->list[i])
	{
		ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
		i++;
		return (check_toptwo(ps, i));
	}
	else if ((*ps->a)->next->val == ps->list[i])
	{
		ps->ans = record_do(sa, ps->ans, ps->a, ps->b);
		ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
		i++;
		return (check_toptwo(ps, i));
	}
	return (i);
}

char	**sort_divided(t_ps *ps)
{
	int	i;
	int	n;
	int	p;

	if ((*ps->b) == NULL)
		return (ps->ans);
	i = ps->index;

	return (sort_divided(ps));
}

char	**solve_half(t_ps *ps)
{
	int	i;
	int	n;
	int	size;

	ps->list = sort_list(ps->a, ps->list);
	ps->list_len = get_stacklen(ps->a);
	size = ps->list_len / 2;
	set_tmp(ps, 0, size);
	sort_divided(ps);
	set_tmp(ps, size, ps->list_len);
	sort_divided(ps);
	return (ps->ans);
}