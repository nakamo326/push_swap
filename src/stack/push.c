#include "stack.h"

static t_stack	*delete_top(t_stack **top)
{
	t_stack	*s_ptr;

	s_ptr = *top;
	if (*top == (*top)->next)
		*top = NULL;
	else
	{
		*top = (*top)->next;
		(*top)->prev = s_ptr->prev;
		s_ptr->prev->next = (*top);
	}
	free(s_ptr);
	return (*top);
}

bool	push(t_stack **out_top, t_stack **in_top)
{
	int	tmp;

	if (*out_top == NULL)
		return (true);
	tmp = (*out_top)->val;
	*out_top = delete_top(out_top);
	*in_top = add_top(in_top, tmp);
	if (in_top == NULL)
		return (false);
	return (true);
}
