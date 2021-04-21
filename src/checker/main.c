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
		return (false);
	do_operation(line, &a_top, &b_top);
	free(line);
	print_stack(a_top);
	print_stack(b_top);
	return (true);
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
	print_stack(a_top);
	while (debug_run(a_top, b_top));
	check_result(a_top, b_top);
	return (0);
}
