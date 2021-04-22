#include "stack.h"

t_stack	*create_newelm(int value)
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

void	free_stack(t_stack **top)
{
	t_stack	*s_ptr;
	t_stack	*tmp;

	if (top == NULL)
		return ;
	s_ptr = *top;
	while (s_ptr)
	{
		tmp = s_ptr->next;
		free(s_ptr);
		s_ptr = tmp;
		if (s_ptr == *top)
			break ;
	}
	free(top);
}

void	print_stack(t_stack **top)
{
	t_stack	*s_ptr;

	ft_putchar_fd('[', 1);
	s_ptr = *top;
	while (s_ptr)
	{
		ft_putnbr_fd(s_ptr->val, 1);
		if (s_ptr->next != *top)
			ft_putstr_fd(", ", 1);
		s_ptr = s_ptr->next;
		if (s_ptr == *top)
			break ;
	}
	ft_putstr_fd("]\n", 1);
	return ;
}

t_stack	*add_top(t_stack **top, int value)
{
	t_stack	*new;
	t_stack	*s_ptr;

	new = create_newelm(value);
	if (new == NULL)
		return (NULL);
	if (*top == NULL)
	{
		new->next = new;
		new->prev = new;
		*top = new;
		return (*top);
	}
	s_ptr = *top;
	new->next = s_ptr;
	new->prev = s_ptr->prev;
	s_ptr->prev = new;
	new->prev->next = new;
	*top = new;
	return (*top);
}

t_stack	*add_bottom(t_stack **top, int value)
{
	t_stack	*new;
	t_stack	*s_ptr;

	new = create_newelm(value);
	if (new == NULL)
		return (NULL);
	if (*top == NULL)
	{
		new->next = new;
		new->prev = new;
		*top = new;
		return (*top);
	}
	s_ptr = *top;
	while (s_ptr->next != *top)
		s_ptr = s_ptr->next;
	s_ptr->next = new;
	new->prev = s_ptr;
	new->next = *top;
	(*top)->prev = new;
	return (*top);
}
