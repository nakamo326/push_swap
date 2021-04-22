#include "checker.h"

static bool	debug_run(t_stack **a_top, t_stack **b_top)
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
		if (do_operation(line, a_top, b_top))
		{
			free(line);
			return (false);
		}
		print_stack(a_top);
		print_stack(b_top);
	}
	free(line);
	return (true);
}

static char	**get_list(void)
{
	int		ret;
	char	*line;
	char	**list;

	list = NULL;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == ERROR)
		{
			list = ft_free_split(list);
			return (NULL);
		}
		list = ft_addstr_split(list, line);
		free(line);
		if (list == NULL)
			return (NULL);
	}
	return (list);
}

static bool	normal_run(t_stack **a_top, t_stack **b_top)
{
	int		i;
	char	*line;
	char	**list;

	list = get_list();
	if (list == NULL)
		return (false);
	i = 0;
	while (list && list[i] != NULL)
	{
		if (do_operation(list[i], a_top, b_top))
		{
			ft_free_split(list);
			return (false);
		}
		i++;
	}
	ft_free_split(list);
	return (true);
}

void	run_operation(t_stack **a_top, t_stack **b_top)
{
	bool	ret;

	if (DEBUG)
		ret = debug_run(a_top, b_top);
	else
		ret = normal_run(a_top, b_top);
	if (ret == false)
	{
		free_stack(a_top);
		free_stack(b_top);
		exit(EXIT_FAILURE);
	}
	return ;
}
