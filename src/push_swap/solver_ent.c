#include "push_swap.h"

char	**solver_ent(t_stack **a_top, t_stack **b_top)
{
	int		len;
	char	**ans;

	ans = NULL;
	len = get_stacklen(a_top);
	if (len == 1)
		return (NULL);
	else if (len == 2)
		return (solve_two(a_top, ans));
	else if (len == 3)
		return (solve_three(a_top, ans));
	else if (len == 4)
		return (solve_four(a_top, b_top, ans));
	else if (len == 5)
		return (solve_five(a_top, b_top, ans));
	else if (len == 6)
		return (solve_six(a_top, b_top, ans));
	else if (len >= 7)
		return (solver(a_top, b_top));
	return (NULL);
}