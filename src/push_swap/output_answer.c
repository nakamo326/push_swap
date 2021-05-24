#include "push_swap.h"

static char	*convert_op(t_op op)
{
	static char	str_set[][4] = {
		"err", "sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"
	};

	return (str_set[op]);
}

void	output_answer(t_op *ans)
{
	int		i;
	char	*str;

	i = 0;
	if (ans == NULL)
		return ;
	while (ans[i] != err)
	{
		str = convert_op(ans[i]);
		ft_putendl_fd(str, 1);
		i++;
	}
	return ;
}
