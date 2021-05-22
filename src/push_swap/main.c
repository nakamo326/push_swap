#include "push_swap.h"

int	wrap_exit(t_ps *ps)
{
	free_stack(ps->a);
	free_stack(ps->b);
	free(ps->list);
	free(ps);
	return (EXIT_SUCCESS);
}

static int	output_error(t_ps *ps)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	wrap_exit(ps);
	return (EXIT_FAILURE);
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
	t_ps	*ps;
	t_stack	**tmp;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	ps = init_ps();
	tmp = create_stack(argv, ps->a);
	if (tmp == NULL)
		return (output_error(ps));
	ps->a = tmp;
	if (!check_stack(ps->a))
		ps->ans = solver_ent(ps);
	merge_operation(ps);
	output_answer(ps->ans);
	ft_free_split(ps->ans);
	return (wrap_exit(ps));
}
