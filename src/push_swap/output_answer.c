#include "push_swap.h"

void	output_answer(char	**ans)
{
	int	i;

	i = 0;
	while (ans[i])
	{
		ft_putendl_fd(ans[i], 1);
		i++;
	}
	return ;
}
