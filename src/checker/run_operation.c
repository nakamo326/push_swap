#include "checker.h"

static bool	free_return(char *line)
{
	free(line);
	return (false);
}

static char	**get_list(char **list, bool *flag)
{
	int		ret;
	char	*line;

	ret = SUCCESS;
	while (ret == SUCCESS)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == END && (line == NULL || *line == '\0'))
		{
			free(line);
			break ;
		}
		if (ret == ERROR || is_valid_op(line) == err)
		{
			*flag = false;
			free(line);
			return (ft_free_split(list));
		}
		list = ft_addstr_split(list, line);
		free(line);
		if (list == NULL)
			return (NULL);
	}
	*flag = true;
	return (list);
}

static bool	debug_run(t_stack **a, t_stack **b, bool *f)
{
	char	*line;
	int		ret;
	int		i;

	i = 0;
	if (f[2] == true)
		output_current(a, b);
	while (1)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == END && (line == NULL || *line == '\0'))
			break ;
		if (ret == ERROR || !is_valid_op(line) || !do_operation(line, a, b))
			return (free_return(line));
		print_stacks(a, b, f, is_valid_op(line));
		free(line);
		i++;
	}
	free(line);
	if (f[3] == true)
		output_result(i, f);
	return (true);
}

static bool	normal_run(t_stack **a, t_stack **b)
{
	int		i;
	char	**list;
	bool	ret;

	list = NULL;
	list = get_list(list, &ret);
	if (ret == false)
		return (false);
	i = 0;
	while (list && list[i] != NULL)
	{
		if (!do_operation(list[i], a, b))
		{
			ft_free_split(list);
			return (false);
		}
		i++;
	}
	ft_free_split(list);
	return (true);
}

void	run_operation(t_stack **a, t_stack **b, bool *op)
{
	bool	ret;

	if (op[0] == true)
		ret = debug_run(a, b, op);
	else
		ret = normal_run(a, b);
	if (ret == false)
		exit(output_error(a, b));
	return ;
}
