#include "checker.h"

static int	output_error(void)
{
	ft_putendl_fd("Error", 2);
	return (EXIT_FAILURE);
}

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

static char	*read_line(void)
{
	char	*buf;
	int		rc;

	buf = malloc(2048);
	if (buf == NULL)
		return (NULL);
	rc = read(STDIN_FILENO, buf, 2047);
	buf[rc] = '\0';
	return (buf);
}

void	run(t_stack **a_top, t_stack **b_top)
{
	char	*line;

	line = read_line();
	if (line == NULL)
		return ;
	do_operation(line, &a_top, &b_top);
	free(line);
	print_stack(a_top);
	print_stack(b_top);
	return ;
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
	while (1)
		run(a_top, b_top);
	return (0);
}
