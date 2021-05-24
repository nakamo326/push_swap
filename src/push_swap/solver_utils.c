#include "push_swap.h"

t_stack	*search_minimum_elm(t_stack **a)
{
	t_stack	*s_ptr;
	t_stack	*minimum;

	s_ptr = *a;
	minimum = s_ptr;
	while (s_ptr)
	{
		if (s_ptr->val < minimum->val)
			minimum = s_ptr;
		s_ptr = s_ptr->next;
		if (s_ptr == *a)
			break ;
	}
	return (minimum);
}

t_dir	search_shortest(t_dir *dir, t_stack **top, t_stack *minimum)
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
	{
		*dir = NEXT;
		return (n_len);
	}
	*dir = PREV;
	return (p_len);
}

static t_op	*repeat_rotate(t_dir dir, int len, t_ps *ps)
{
	int		i;
	t_op	op;

	if (dir == NEXT)
		op = ra;
	else
		op = rra;
	i = 0;
	while (i < len)
	{
		ps->ans = record_do(op, ps);
		if (ps->ans == NULL)
			return (NULL);
		i++;
	}
	return (ps->ans);
}

t_op	*pb_mininum(t_ps *ps)
{
	t_stack	*s;
	t_dir	dir;
	int		len;

	s = search_minimum_elm(ps->a);
	len = search_shortest(&dir, ps->a, s);
	ps->ans = repeat_rotate(dir, len, ps);
	ps->ans = record_do(pb, ps);
	return (ps->ans);
}
