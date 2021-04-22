#include "checker.h"

static int	exit_free(t_stack **a_top, t_stack **b_top)
{
	free_stack(a_top);
	free_stack(b_top);
	return (0);
}

static int	output_error(t_stack **a_top, t_stack **b_top)
{
	ft_putendl_fd("Error", 2);
	exit_free(a_top, b_top);
	return (EXIT_FAILURE);
}

static void	init_stack(t_stack ***a_top, t_stack ***b_top)
{
	*a_top = malloc(sizeof(t_stack *));
	if (*a_top == NULL)
		exit(EXIT_FAILURE);
	**a_top = NULL;
	*b_top = malloc(sizeof(t_stack *));
	if (*b_top == NULL)
	{
		free(*a_top);
		exit(EXIT_FAILURE);
	}
	**b_top = NULL;
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	**a_top;
	t_stack	**b_top;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	init_stack(&a_top, &b_top);
	if (!is_valid_arg(argv))
		return (output_error(a_top, b_top));
	a_top = create_stack(argv, a_top);
	if (a_top == NULL)
		return (output_error(NULL, b_top));
	run_operation(a_top, b_top);
	check_result(a_top, b_top);
	return (exit_free(a_top, b_top));
}
