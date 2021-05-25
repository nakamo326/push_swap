#include "stack.h"

char	*convert_op(t_op op)
{
	static char	str_set[][4] = {
		"err", "sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"
	};

	return (str_set[op]);
}
