#include "stack.h"

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

static bool	is_valid_num(char *arg, t_stack **top)
{
	long long	value;
	int			i;

	i = 0;
	if (!(ft_isdigit(arg[i]) || arg[i] == '-' || arg[i] == '+'))
		return (false);
	i++;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (false);
		i++;
	}
	if (!ft_strncmp(arg, "-", 2) || !ft_strncmp(arg, "+", 2)
		|| ft_strlen(arg) > (size_t)12)
		return (false);
	value = ft_atoll(arg);
	if (value > INT_MAX || value < INT_MIN || !check_dup(value, top))
		return (false);
	return (true);
}

static bool	is_able_to_split(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		while (ft_isspace(arg[i]))
			i++;
		if (!(ft_isdigit(arg[i]) || arg[i] == '-' || arg[i] == '+')
			|| arg[i] == '\0')
			return (false);
		i++;
		while (ft_isdigit(arg[i]))
			i++;
		if (!ft_isspace(arg[i]) && arg[i] != '\0')
			return (false);
	}
	return (true);
}

static t_stack	**add_split(char *arg, t_stack **top)
{
	char		**split;
	long long	value;
	int			i;

	split = ft_split(arg, ' ');
	if (split == NULL)
		return (NULL);
	i = 0;
	while (split[i] != NULL)
	{
		if (!is_valid_num(split[i], top))
			return (ft_free_split(split));
		value = ft_atoll(split[i]);
		*top = add_bottom(top, (int)value);
		if (*top == NULL)
			return (ft_free_split(split));
		i++;
	}
	ft_free_split(split);
	return (top);
}

t_stack	**create_stack(char **argv, t_stack **top, int i)
{
	long long	value;

	while (argv[i] != NULL)
	{
		if (argv[i][0] == '\0')
			return (NULL);
		if (is_able_to_split(argv[i]))
		{
			top = add_split(argv[i], top);
			if (top == NULL)
				return (NULL);
			i++;
			continue ;
		}
		if (!is_valid_num(argv[i], top))
			return (NULL);
		value = ft_atoll(argv[i]);
		*top = add_bottom(top, (int)value);
		if (*top == NULL)
			return (NULL);
		i++;
	}
	return (top);
}
