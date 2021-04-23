#include "push_swap.h"

static int	exit_free(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	return (0);
}

static int	output_error(t_stack **a, t_stack **b)
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

static bool	check_stack(t_stack **a)
{
	int		tmp;
	t_stack	*s_ptr;

	tmp = (*a)->val;
	s_ptr = (*a)->next;
	while (s_ptr)
	{
		if (s_ptr == *a)
			break ;
		if (tmp > s_ptr->val)
			return (false);
		tmp = s_ptr->val;
		s_ptr = s_ptr->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	char	**ans;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	init_stack(&a, &b);
	if (!is_valid_arg(argv))
		return (output_error(a, b));
	a = create_stack(argv, a);
	if (a == NULL)
		return (output_error(NULL, b));
	if (!check_stack(a))
		ans = solver_ent(a, b);
	output_answer(ans);
	ft_free_split(ans);
	return (exit_free(a, b));
}
