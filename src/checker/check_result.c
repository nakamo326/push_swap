#include "checker.h"

void	check_result(t_stack **a, t_stack **b)
{
	int		tmp;
	t_stack	*s_ptr;

	if (*b != NULL)
		return (output_ko());
	tmp = (*a)->val;
	s_ptr = (*a)->next;
	while (s_ptr)
	{
		if (s_ptr == *a)
			break ;
		if (tmp > s_ptr->val)
			return (output_ko());
		tmp = s_ptr->val;
		s_ptr = s_ptr->next;
	}
	return (output_ok());
}
