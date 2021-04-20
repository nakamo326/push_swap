#include "stack.h"

void	free_stack(t_stack **top)
{
	t_stack	*s_ptr;
	t_stack	*tmp;

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
