#include "stack.h"

static t_stack	*create_newelm(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->val = value;
	return (new);
}

static t_stack	**add_newelm(t_stack **top, int value)
{
	t_stack	*new;
	t_stack	*s_ptr;

	new = create_newelm(value);
	if (new == NULL)
		return (NULL);
	if (top == NULL)
	{
		new->next = new;
		new->prev = new;
		top = malloc(sizeof(t_stack **));
		*top = new;
		return (top);
	}
	s_ptr = *top;
	while(s_ptr->next != *top)
		s_ptr = s_ptr->next;
	s_ptr->next = new;
	new->prev = s_ptr;
	new->next = *top;
	(*top)->prev = new;
	return (top);
}

t_stack	**create_stack(char **argv, t_stack **top)
{
	long long	value;
	int			i;
	//t_list		**tmp;

	i = 1;
	while (argv[i] != NULL)
	{
		value = ft_atoll(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			//free_stack(top);
			return (NULL);
		}
		//tmp = top;
		top = add_newelm(top, (int)value);
		if (top == NULL)
		{
			//free_stack(tmp);
			return (NULL);
		}
		i++;
	}
	return (top);
}