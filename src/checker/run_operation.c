#include "checker.h"

static char	**get_list(char **list, bool *flag)
{
	int		ret;
	char	*line;

	ret = SUCCESS;
	while (ret == SUCCESS)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == END && (line == NULL || *line == '\0'))
			break ;
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
	free(line);
	*flag = true;
	return (list);
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

static void	print_stacks(t_stack **a, t_stack **b, bool f, t_op op)
{
	if (f == false)
	{
		print_stack(a);
		print_stack(b);
	}
	print_color_stacks(a, b, op);
	return ;
}

static bool	debug_run(t_stack **a, t_stack **b, bool f)
{
	char	*line;
	int		rc;

	line = malloc(2048);
	if (line == NULL)
		return (false);
	while (1)
	{
		rc = read(STDIN_FILENO, line, 2047);
		line[rc] = '\0';
		if (rc == 0)
			break ;
		if (!do_operation(line, a, b))
		{
			free(line);
			return (false);
		}
		print_stacks(a, b, f, is_valid_op(line));
	}
	free(line);
	return (true);
}

void	run_operation(t_stack **a, t_stack **b, bool *op)
{
	bool	ret;

	if (op[0] == true)
		ret = debug_run(a, b, op[1]);
	else
		ret = normal_run(a, b);
	if (ret == false)
		exit(output_error(a, b));
	return ;
}
