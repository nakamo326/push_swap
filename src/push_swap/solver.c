#include "push_swap.h"

//repeat push most smallest elm to B until last 2 elm
//swap or not swap
//push all elm to A

static t_stack	*search_minimum_elm(t_stack **a_top)
{
	t_stack	*s_ptr;
	t_stack	*minimum;

	s_ptr = *a_top;
	minimum = s_ptr;
	while (s_ptr)
	{
		if (s_ptr->val < minimum->val)
			minimum = s_ptr;
		s_ptr = s_ptr->next;
		if (s_ptr == *a_top)
			break ;
	}
	return (minimum);
}

static t_dir	search_shortest(t_stack **top, t_stack ** minimum)
{
	int		n_len;
	int		p_len;
	t_stack	*s_ptr;

	n_len = 0;
	s_ptr = *top;
	while (s_ptr != minimum)
	{
		s_ptr = s_ptr->next;
		n_len++;
	}
	p_len = 0;
	s_ptr = *top;
	while (s_ptr != minimum)
	{
		s_ptr = s_ptr->prev;
		p_len++;
	}
	if (n_len <= p_len)
		return (NEXT);
	return (PREV);
}

bool	solver(t_stack **a_top, t_stack **b_top)
{
	char	**ans;
	t_stack	*s_ptr;
	t_dir	dir;

	ans = NULL;
	while (*a_top == (*a_top)->next)
	{
		s_ptr = search_minimum_elm(a_top);
		dir = search_shortest(a_top, s_ptr);

	}


}