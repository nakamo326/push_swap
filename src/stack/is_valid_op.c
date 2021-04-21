#include "stack.h"

t_op	is_valid_op(char *line)
{
	if (!ft_strncmp(line, "sa\n", 4) || !ft_strncmp(line, "sa", 3))
		return (sa);
	if (!ft_strncmp(line, "sb\n", 4) || !ft_strncmp(line, "sb", 3))
		return (sb);
	if (!ft_strncmp(line, "ss\n", 4) || !ft_strncmp(line, "ss", 3))
		return (ss);
	if (!ft_strncmp(line, "pa\n", 4) || !ft_strncmp(line, "pa", 3))
		return (pa);
	if (!ft_strncmp(line, "pb\n", 4) || !ft_strncmp(line, "pb", 3))
		return (pb);
	if (!ft_strncmp(line, "ra\n", 4) || !ft_strncmp(line, "ra", 3))
		return (ra);
	if (!ft_strncmp(line, "rb\n", 4) || !ft_strncmp(line, "rb", 3))
		return (rb);
	if (!ft_strncmp(line, "rr\n", 4) || !ft_strncmp(line, "rr", 3))
		return (rr);
	if (!ft_strncmp(line, "rra\n", 5) || !ft_strncmp(line, "rra", 4))
		return (rra);
	if (!ft_strncmp(line, "rrb\n", 5) || !ft_strncmp(line, "rrb", 4))
		return (rrb);
	if (!ft_strncmp(line, "rrr\n", 5) || !ft_strncmp(line, "rrr", 4))
		return (rrr);
	return (err);
}
