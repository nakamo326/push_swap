#include "checker.h"

static int	output_help(void)
{
	ft_putendl_fd("working oprions are v, c", 2);
	ft_putendl_fd("please input atfer \"-\" to first argument", 2);
	return (0);
}

int	get_option(char **argv, bool *op_flag)
{
	int	num;
	int	i;

	if (argv[1][0] != '-')
		return (1);
	num = 2;
	i = 1;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == 'v')
			op_flag[0] = true;
		else if (argv[1][i] == 'c')
			op_flag[1] = true;
		else
			return (output_help());
		i++;
	}
	return (num);
}