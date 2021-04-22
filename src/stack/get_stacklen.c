#include "stack.h"

int	get_stacklen(t_stack **top)
{
	int		len;
	t_stack	*s_ptr;

	s_ptr = *top;
	len = 0;
	while(s_ptr)
	{
		s_ptr = s_ptr->next;
		len++;
		if (s_ptr == *top)
			break ;
	}
	return (len);
}