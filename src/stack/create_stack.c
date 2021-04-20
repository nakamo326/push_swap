#include "stack.h"

t_stack	**create_stack(char **argv, t_stack **top)
{
	long long	value;
	int			i;
	t_stack		**tmp;

	i = 1;
	while (argv[i] != NULL)
	{
		value = ft_atoll(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
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
