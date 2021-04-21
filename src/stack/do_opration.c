#include "stack.h"
//各operationが成功かどうかをboolで返す？

static bool	swap_ent(t_op op, t_stack ***a_top, t_stack ***b_top)
{
	if (op == sa)
		return (swap(a_top));
	else if (op == sb)
		return (swap(b_top));
	return (swap(a_top) && swap(b_top));
}

static bool	push_ent(t_op op, t_stack ***a_top, t_stack ***b_top)
{
	if (op == pa)
		return (push(b_top, a_top));
	return (push(a_top, b_top));
}

static bool	rotate_ent(t_op op, t_stack ***a_top, t_stack ***b_top)
{
	if (op == ra)
		return (rotate(a_top));
	else if (op == rb)
		return (rotate(b_top));
	return (rotate(a_top) && rotate(b_top));
}

static bool	rev_rotate_ent(t_op op, t_stack ***a_top, t_stack ***b_top)
{
	if (op == rra)
		return (rev_rotate(a_top));
	else if (op == rrb)
		return (rev_rotate(b_top));
	return (rev_rotate(a_top) && rev_rotate(b_top));
}

bool	do_operation(char *line, t_stack ***a_top, t_stack ***b_top)
{
	t_op	op;

	op = is_valid_op(line);
	if (op == sa || op == sb || op == ss)
		return (swap_ent(op, a_top, b_top));
	else if (op == pa || op == pb)
		return (push_ent(op, a_top, b_top));
	else if (op == ra || op == rb || op == rr)
		return (rotate_ent(op, a_top, b_top));
	else if (op == rra || op == rrb || op == rrr)
		return (rev_rotate_ent(op, a_top, b_top));
	return (false);
}
