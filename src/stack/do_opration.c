#include "stack.h"

static bool	swap_ent(t_op op, t_stack **a, t_stack **b)
{
	if (op == sa)
		return (swap(a));
	else if (op == sb)
		return (swap(b));
	return (swap(a) && swap(b));
}

static bool	push_ent(t_op op, t_stack **a, t_stack **b)
{
	if (op == pa)
		return (push(b, a));
	return (push(a, b));
}

static bool	rotate_ent(t_op op, t_stack **a, t_stack **b)
{
	if (op == ra)
		return (rotate(a));
	else if (op == rb)
		return (rotate(b));
	return (rotate(a) && rotate(b));
}

static bool	rev_rotate_ent(t_op op, t_stack **a, t_stack **b)
{
	if (op == rra)
		return (rev_rotate(a));
	else if (op == rrb)
		return (rev_rotate(b));
	return (rev_rotate(a) && rev_rotate(b));
}

bool	do_operation(char *line, t_stack **a, t_stack **b)
{
	t_op	op;

	op = is_valid_op(line);
	if (op == sa || op == sb || op == ss)
		return (swap_ent(op, a, b));
	else if (op == pa || op == pb)
		return (push_ent(op, a, b));
	else if (op == ra || op == rb || op == rr)
		return (rotate_ent(op, a, b));
	else if (op == rra || op == rrb || op == rrr)
		return (rev_rotate_ent(op, a, b));
	return (false);
}
