#include "checker.h"

static bool	debug_run(t_stack **a, t_stack **b)
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
		print_stack(a);
		print_stack(b);
	}
	free(line);
	return (true);
}

static bool	get_list(char ***list)
{
	int		ret;
	char	*line;

	ret = SUCCESS;
	while (ret == SUCCESS)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == ERROR)
		{
			*list = ft_free_split(*list);
			return (false);
		}
		if (ret == END && (line == NULL || *line == '\0'))
		{
			free(line);
			break ;
		}
		*list = ft_addstr_split(*list, line);
		free(line);
		if (*list == NULL)
			return (NULL);
	}
	return (true);
}

static bool	normal_run(t_stack **a, t_stack **b)
{
	int		i;
	char	**list;

	list = NULL;
	if (!get_list(&list))
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

void	run_operation(t_stack **a, t_stack **b)
{
	bool	ret;

	if (DEBUG)
		ret = debug_run(a, b);
	else
		ret = normal_run(a, b);
	if (ret == false)
	{
		output_error(a, b);
		exit(EXIT_FAILURE);
	}
	return ;
}
