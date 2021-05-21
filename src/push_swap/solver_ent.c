#include "push_swap.h"

char	**solver_ent(t_ps *ps)
{
	int		len;
	char	**ans;

	ans = NULL;
	len = get_stacklen(ps->a);
	if (len == 1)
		return (NULL);
	else if (len == 2)
		return (solve_two(ps->a, ans));
	else if (len == 3)
		return (solve_three(ps->a, ans));
	else if (len == 4)
		return (solve_four(ps->a, ps->b, ans));
	else if (len == 5)
		return (solve_five(ps->a, ps->b, ans));
	else if (len == 6)
		return (solve_six(ps->a, ps->b, ans));
	else if (len >= 7)
		return (solve_half(ps));
	return (NULL);
}
