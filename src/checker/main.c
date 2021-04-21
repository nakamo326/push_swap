#include "checker.h"

static bool	is_valid_arg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		if (!(ft_isdigit(argv[i][j]) || argv[i][j] == '-'))
			return (false);
		j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	debug_run(t_stack **a_top, t_stack **b_top)
{
	char	*line;
	int		rc;

	line = malloc(2048);
	if (line == NULL)
		return (NULL);
	rc = read(STDIN_FILENO, line, 2047);
	line[rc] = '\0';
	if (rc == 0)
	{
		free(line);
		return (false);
	}
	do_operation(line, &a_top, &b_top);
	free(line);
	print_stack(a_top);
	print_stack(b_top);
	return (true);
}

static void	run_operation(t_stack **a_top, t_stack **b_top)
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
			break ;
		}
		list = ft_addstr_split(list, line);
		free(line);
	}
	ret = 0;
	while (list && list[ret] != NULL)
	{
		do_operation(list[ret], &a_top, &b_top);
		ret++;
	}
	ft_free_split(list);
	return ;
}

static int	exit_free(t_stack **a_top, t_stack **b_top)
{
	free_stack(a_top);
	free_stack(b_top);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**a_top;
	t_stack	**b_top;

	if (argc == 1)
		return (0);
	a_top = malloc(sizeof(t_stack *));
	*a_top = NULL;
	b_top = malloc(sizeof(t_stack *));
	*b_top = NULL;
	if (argc <= 1)
		exit(EXIT_FAILURE);
	if (!is_valid_arg(argv))
		return (output_error());
	a_top = create_stack(argv, a_top);
	if (a_top == NULL)
		return (output_error());
	if (DEBUG)
		while (debug_run(a_top, b_top))
			continue ;
	else
		run_operation(a_top, b_top);
	check_result(a_top, b_top);
	return (exit_free(a_top, b_top));
}
