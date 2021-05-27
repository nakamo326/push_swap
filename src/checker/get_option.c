#include "checker.h"

static int	output_help(void)
{
	ft_putendl_fd("working oprions are v, c, s, r", 2);
	ft_putendl_fd("v ... print stack after each operation.", 2);
	ft_putendl_fd("c ... coloring operation and result.", 2);
	ft_putendl_fd("s ... clear screen after each op.(need v option)", 2);
	ft_putendl_fd("r ... print score result", 2);
	ft_putendl_fd("please input atfer \"--\" to first argument", 2);
	return (0);
}

static void	init_flag(bool *f)
{
	int	num;
	int	i;

	num = 4;
	i = 0;
	while (i < num)
	{
		f[i] = false;
		i++;
	}
	return ;
}

int	get_option(char **argv, bool *op_flag)
{
	int	num;
	int	i;

	init_flag(op_flag);
	if (argv[1][0] != '-' && argv[1][1] != '-')
		return (1);
	num = 2;
	i = 2;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == 'v')
			op_flag[0] = true;
		else if (argv[1][i] == 'c')
			op_flag[1] = true;
		else if (argv[1][i] == 's')
			op_flag[2] = true;
		else if (argv[1][i] == 'r')
			op_flag[3] = true;
		else
			return (output_help());
		i++;
	}
	return (num);
}
