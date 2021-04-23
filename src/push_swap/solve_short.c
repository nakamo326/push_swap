#include "push_swap.h"

char	**solve_two(t_stack **top, char **ans)
{
	if ((*top)->val > (*top)->next->val)
		ans = record_do(ra, ans, top, NULL);
	return (ans);
}

char	**solve_three(t_stack **top, char **ans)
{
	const int	first = (*top)->val;
	const int	second = (*top)->next->val;
	const int	third = (*top)->next->next->val;

	if (first > second && second < third && first < third)
		return (record_do(sa, ans, top, NULL));
	else if (first < second && second > third && first > third)
		return (record_do(rra, ans, top, NULL));
	else if (first > second && second < third && first > third)
		return (record_do(ra, ans, top, NULL));
	else if (first > second && second > third && first > third)
	{
		ans = record_do(ra, ans, top, NULL);
		return (record_do(sa, ans, top, NULL));
	}
	else if (first < second && second > third && first < third)
	{
		ans = record_do(sa, ans, top, NULL);
		return (record_do(ra, ans, top, NULL));
	}
	return (ans);
}

char	**solve_four(t_stack **a_top, t_stack **b_top, char **ans)
{
	ans = pb_mininum(a_top, b_top, ans);
	ans = solve_three(a_top, ans);
	ans = record_do(pa, ans, a_top, b_top);
	return (ans);
}

char	**solve_five(t_stack **a_top, t_stack **b_top, char **ans)
{
	ans = pb_mininum(a_top, b_top, ans);
	ans = solve_four(a_top, b_top, ans);
	ans = record_do(pa, ans, a_top, b_top);
	return (ans);
}