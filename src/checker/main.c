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
	t_stack	**a;
	t_stack	**b;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	init_stack(&a, &b);
	if (!is_valid_arg(argv))
		return (output_error(a, b));
	a = create_stack(argv, a);
	if (a == NULL)
		return (output_error(NULL, b));
	run_operation(a, b);
	check_result(a, b);
	return (exit_free(a, b));
}
