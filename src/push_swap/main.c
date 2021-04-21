#include "push_swap.h"

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

	if (argc <= 1)
		exit(EXIT_FAILURE);
	a_top = malloc(sizeof(t_stack *));
	*a_top = NULL;
	b_top = malloc(sizeof(t_stack *));
	*b_top = NULL;
	if (!is_valid_arg(argv))
		return (output_error());
	a_top = create_stack(argv, a_top);
	if (a_top == NULL)
		return (output_error());
	solver(a_top, b_top);
	return (exit_free(a_top, b_top));
}
