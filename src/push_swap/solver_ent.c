#include "push_swap.h"

t_op	*solver_ent(t_ps *ps)
{
	int		len;

	len = get_stacklen(ps->a);
	if (len == 1)
		return (NULL);
	else if (len == 2)
		return (solve_two(ps));
	else if (len == 3)
		return (solve_three(ps->a, ps));
	else if (len == 4)
		return (solve_four(ps));
	else if (len == 5)
		return (solve_five(ps));
	else if (len == 6)
		return (solve_six(ps));
	else if (len >= 7)
		return (solve_quick(ps));
	return (NULL);
}
