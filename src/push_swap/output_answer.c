#include "push_swap.h"

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
