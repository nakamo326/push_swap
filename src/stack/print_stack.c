#include "stack.h"

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