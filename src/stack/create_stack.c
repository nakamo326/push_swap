#include "stack.h"

//duplicate check
static bool	check_dup(int value, t_stack **top)
{
	t_stack	*s_ptr;

	s_ptr = *top;
	while (s_ptr)
	{
		if (value == s_ptr->val)
			return (false);
		if (s_ptr->next == *top)
			break ;
		s_ptr = s_ptr->next;
	}
	return (true);
}

t_stack	**create_stack(char **argv, t_stack **top)
{
	long long	value;
	int			i;
	t_stack		**tmp;

	i = 1;
	while (argv[i] != NULL)
	{
		value = ft_atoll(argv[i]);
		if (value > INT_MAX || value < INT_MIN || !check_dup(value, top))
		{
			free_stack(top);
			return (NULL);
		}
		tmp = top;
		top = add_bottom(top, (int)value);
		if (top == NULL)
		{
			free_stack(tmp);
			return (NULL);
		}
		i++;
	}
	return (top);
}
