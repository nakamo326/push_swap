#include "stack.h"

t_op	is_valid_op(char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		return (sa);
	if (!ft_strncmp(line, "sb\n", 4))
		return (sb);
	if (!ft_strncmp(line, "ss\n", 4))
		return (ss);
	if (!ft_strncmp(line, "pa\n", 4))
		return (pa);
	if (!ft_strncmp(line, "pb\n", 4))
		return (pb);
	if (!ft_strncmp(line, "ra\n", 4))
		return (ra);
	if (!ft_strncmp(line, "rb\n", 4))
		return (rb);
	if (!ft_strncmp(line, "rr\n", 4))
		return (rr);
	if (!ft_strncmp(line, "rra\n", 5))
		return (rra);
	if (!ft_strncmp(line, "rrb\n", 5))
		return (rrb);
	if (!ft_strncmp(line, "rrr\n", 5))
		return (rrr);
	return (err);
}
