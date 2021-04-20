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

void	run(t_stack **a_top, t_stack **b_top)
{
	char *line;
	line = read_line();
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

	a_top = malloc(sizeof(t_stack *));
	*a_top = NULL;
	b_top = malloc(sizeof(t_stack *));
	*b_top = NULL;
	if (argc <= 1)
		exit(EXIT_FAILURE);
	if (!is_valid_arg(argv))
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	a_top = create_stack(argv, a_top);
	while (1)
		run(a_top, b_top);


	return (0);
}
