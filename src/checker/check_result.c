#include "checker.h"

void	check_result(t_stack **a_top, t_stack **b_top)
{
	int		tmp;
	t_stack	*s_ptr;

	if (*b_top != NULL)
		return (output_ko());
	tmp = (*a_top)->val;
	s_ptr = (*a_top)->next;
	while (s_ptr)
	{
		if (s_ptr == *a_top)
			break ;
		if (tmp > s_ptr->val)
			return (output_ko());
		tmp = s_ptr->val;
		s_ptr = s_ptr->next;
	}
	return (output_ok());
}
