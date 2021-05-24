#include "push_swap.h"

t_op	*solve_two(t_ps *ps)
{
	if ((*ps->a)->val > (*ps->a)->next->val)
		ps->ans = record_do(ra, ps);
	return (ps->ans);
}

t_op	*solve_three(t_stack **top, t_ps *ps)
{
	const int	first = (*top)->val;
	const int	second = (*top)->next->val;
	const int	third = (*top)->next->next->val;

	if (first > second && second < third && first < third)
		return (record_do(sa, ps));
	else if (first < second && second > third && first > third)
		return (record_do(rra, ps));
	else if (first > second && second < third && first > third)
		return (record_do(ra, ps));
	else if (first > second && second > third && first > third)
	{
		ps->ans = record_do(ra, ps);
		return (record_do(sa, ps));
	}
	else if (first < second && second > third && first < third)
	{
		ps->ans = record_do(sa, ps);
		return (record_do(ra, ps));
	}
	return (ps->ans);
}

t_op	*solve_four(t_ps *ps)
{
	ps->ans = pb_mininum(ps);
	ps->ans = solve_three(ps->a, ps);
	ps->ans = record_do(pa, ps);
	return (ps->ans);
}

t_op	*solve_five(t_ps *ps)
{
	ps->ans = pb_mininum(ps);
	ps->ans = solve_four(ps);
	ps->ans = record_do(pa, ps);
	return (ps->ans);
}

t_op	*solve_six(t_ps *ps)
{
	ps->ans = pb_mininum(ps);
	ps->ans = solve_five(ps);
	ps->ans = record_do(pa, ps);
	return (ps->ans);
}
