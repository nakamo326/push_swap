#include "push_swap.h"

static void	three_push_rotate(t_ps *ps)
{
	ps->ans = record_do(pa, ps);
	ps->ans = record_do(pa, ps);
	ps->ans = record_do(pa, ps);
	ps->ans = record_do(ra, ps);
	ps->ans = record_do(ra, ps);
	ps->ans = record_do(ra, ps);
}

bool	check_three_elm(t_ps *ps)
{
	if (ps->i + 2 >= ps->list_len)
		return (false);
	if ((*ps->b)->next->next->val == ps->list[ps->i])
	{
		if ((*ps->b)->val == ps->list[ps->i + 2]
			&& (*ps->b)->next->val == ps->list[ps->i + 1])
		{
			three_push_rotate(ps);
			ps->i = ps->i + 3;
			return (true);
		}
		if ((*ps->b)->val == ps->list[ps->i + 1]
			&& (*ps->b)->next->val == ps->list[ps->i + 2])
		{
			ps->ans = record_do(sb, ps);
			three_push_rotate(ps);
			ps->i = ps->i + 3;
			return (true);
		}
	}
	return (false);
}

void	set_first(t_ps *ps, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (((*ps->a)->val <= ps->list[size - 1]))
		{
			ps->ans = record_do(pb, ps);
			i++;
		}
		else
			ps->ans = record_do(ra, ps);
	}
}
