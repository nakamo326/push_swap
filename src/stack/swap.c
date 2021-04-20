#include "stack.h"

bool	swap(t_stack ***top)
{
	int	tmp;

	if (**top == (**top)->next)
		return (true);
	tmp = (**top)->val;
	(**top)->val = (**top)->next->val;
	(**top)->next->val = tmp;
	return (true);
}
