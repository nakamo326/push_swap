#include "checker.h"

static int	exit_free(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	return (0);
}

int	output_error(t_stack **a, t_stack **b)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit_free(a, b);
	return (EXIT_FAILURE);
}

static void	init_stack(t_stack ***a, t_stack ***b)
{
	*a = malloc(sizeof(t_stack *));
	if (*a == NULL)
		exit(EXIT_FAILURE);
	**a = NULL;
	*b = malloc(sizeof(t_stack *));
	if (*b == NULL)
	{
		free(*a);
		exit(EXIT_FAILURE);
	}
	**b = NULL;
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	**s[3];
	int		i;
	bool	op_flag[3];

	if (argc <= 1)
		exit(EXIT_FAILURE);
	init_stack(&s[0], &s[1]);
	i = get_option(argv, op_flag);
	if (i == 0)
		return (exit_free(s[0], s[1]));
	s[2] = create_stack(argv, s[0], i);
	if (s[2] == NULL)
		return (output_error(s[0], s[1]));
	s[0] = s[2];
	run_operation(s[0], s[1], op_flag);
	check_result(s[0], s[1], op_flag[1]);
	return (exit_free(s[0], s[1]));
}
