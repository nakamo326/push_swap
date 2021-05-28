#include "checker.h"

static int	free_return(char *line, int ret)
{
	free(line);
	return (ret);
}

static int	get_next_op(t_op *op)
{
	char	*line;
	int		ret;

	*op = err;
	ret = get_next_line(STDIN_FILENO, &line);
	if (ret == END && (line == NULL || *line == '\0'))
		return (free_return(line, END));
	if (ret == ERROR || !is_valid_op(line))
		free_return(line, ERROR);
	*op = is_valid_op(line);
	return (free_return(line, ret));
}

void	run_operation(t_stack **a, t_stack **b, bool *f)
{
	t_op	op;
	int		ret;
	int		i;

	i = 0;
	if (f[2] == true)
		output_current(a, b);
	ret = SUCCESS;
	while (ret == SUCCESS)
	{
		ret = get_next_op(&op);
		if (ret == END && op == err)
			break ;
		if (ret == ERROR || !do_operation(op, a, b))
			exit(output_error(a, b));
		if (f[0] == true)
			print_stacks(a, b, f, op);
		i++;
	}
	if (f[3] == true)
		output_result(i, f);
	return ;
}
