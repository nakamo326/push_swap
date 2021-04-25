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

static char	**repeat_rotate(t_dir dir, int len, char **ans, t_stack **a)
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
		ans = record_do(op, ans, a, NULL);
		if (ans == NULL)
			return (NULL);
		i++;
	}
	return (ans);
}

char	**pb_mininum(t_stack **a, t_stack **b, char **ans)
{
	t_stack	*s;
	t_dir	dir;
	int		len;

	s = search_minimum_elm(a);
	len = search_shortest(&dir, a, s);
	ans = repeat_rotate(dir, len, ans, a);
	ans = record_do(pb, ans, a, b);
	return (ans);
}

char	**solver(t_stack **a, t_stack **b)
{
	char	**ans;

	ans = NULL;
	while (*a != (*a)->next)
	{
		ans = pb_mininum(a, b, ans);
		if (ans == NULL)
			return (NULL);
	}
	while (*b != NULL)
	{
		ans = record_do(pa, ans, a, b);
		if (ans == NULL)
			return (NULL);
	}
	return (ans);
}
