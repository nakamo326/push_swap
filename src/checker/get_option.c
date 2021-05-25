#include "checker.h"

int	get_option(char **argv, bool *op_flag)
{
	(void)op_flag;
	if (argv[1][0] != '-')
		return (1);
	return 1;
}