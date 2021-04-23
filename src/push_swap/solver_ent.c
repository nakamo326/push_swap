#include "push_swap.h"

char	**solver_ent(t_stack **a, t_stack **b)
{
	int		len;
	char	**ans;

	ans = NULL;
	len = get_stacklen(a);
	if (len == 1)
		return (NULL);
	else if (len == 2)
		return (solve_two(a, ans));
	else if (len == 3)
		return (solve_three(a, ans));
	else if (len == 4)
		return (solve_four(a, b, ans));
	else if (len == 5)
		return (solve_five(a, b, ans));
	else if (len == 6)
		return (solve_six(a, b, ans));
	else if (len >= 7)
		return (solver(a, b));
	return (NULL);
}