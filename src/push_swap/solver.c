#include "push_swap.h"

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

static t_dir	search_shortest(t_dir *dir, t_stack **top, t_stack *minimum)
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

static char	**repeat_rotate(t_dir dir, int len, char **ans, t_stack ***a_top)
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
		ans = record_do(op, ans, a_top, NULL);
		i++;
	}
	return (ans);
}

//malloc error handling!!!

bool	solver(t_stack **a_top, t_stack **b_top)
{
	char	**ans;
	t_stack	*s_ptr;
	t_dir	dir;
	int		len;

	ans = NULL;
	while (*a_top != (*a_top)->next)
	{
		s_ptr = search_minimum_elm(a_top);
		len = search_shortest(&dir, a_top, s_ptr);
		ans = repeat_rotate(dir, len, ans, &a_top);
		ans = record_do(pb, ans, &a_top, &b_top);
		if (ans == NULL)
		{
			ft_putendl_fd("Error", 2);
			return (false);
		}
	}
	while (*b_top != NULL)
		ans = record_do(pa, ans, &a_top, &b_top);
	output_answer(ans);
	ft_free_split(ans);
	return (true);

}