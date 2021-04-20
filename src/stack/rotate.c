#include "stack.h"

bool	rotate(t_stack ***top)
{
	if (**top == NULL)
		return (true);
	**top = (**top)->next;
	return (true);
}

bool	rev_rotate(t_stack ***top)
{
	if (**top == NULL)
		return (true);
	**top = (**top)->prev;
	return (true);
}