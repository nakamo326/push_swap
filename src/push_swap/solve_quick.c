#include "push_swap.h"
#include <stdio.h>

int	get_sortsize(int stacklen)
{
	if (stacklen <= 50)
		return (10);
	if (stacklen <= 100)
		return (25);
	if (stacklen <= 300)
		return (50);
	return (50);
}

bool	divide_stack(t_ps *ps, int start, int end)
{
	t_stack	*s_ptr;
	int		i;
	int		r;

	s_ptr = *ps->a;
	if (end > ps->list_len)
		end = ps->list_len;
	i = start;
	r = 0;
	while(i < end)
	{
		if (s_ptr->val >= ps->list[start] && s_ptr->val <= ps->list[end - 1])
		{
			ps->ans = record_do(pb, ps->ans, &s_ptr, ps->b);
			i++;
		}
		else
		{
			ps->ans = record_do(ra, ps->ans, &s_ptr, ps->b);
			r++;
		}
		if (s_ptr == NULL)
			break ;
	}
	i = 0;
	while (i < r)
	{
		ps->ans = record_do(rra, ps->ans, &s_ptr, ps->b);
		i++;
	}
	*ps->a = s_ptr;
	//print_stack(ps->b);
	return (true);
}

static char	**repeat_rotate(t_dir dir, int len, char **ans, t_stack **b)
{
	int		i;
	t_op	op;

	if (dir == NEXT)
		op = rb;
	else
		op = rrb;
	i = 0;
	while (i < len)
	{
		ans = record_do(op, ans, NULL, b);
		if (ans == NULL)
			return (NULL);
		i++;
	}
	return (ans);
}

char	**sort_divided(t_ps *ps, int i)
{
	t_stack	*s;
	t_dir	dir;
	int		len;

	ft_putendl_fd("start sorting devided", 2);
	print_stack(ps->b);
	while (*(ps->b) != NULL && i < ps->list_len)
	{
		if ((*ps->b)->val == ps->list[i])
		{
			ps->ans = record_do(pa, ps->ans, ps->a, ps->b);
			ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
			print_stack(ps->a);
			i++;
		}
		else
		{
			s = search_minimum_elm(ps->b);
			len = search_shortest(&dir, ps->b, s);
			ps->ans = repeat_rotate(dir, len, ps->ans, ps->b);
		}
	}
	return (ps->ans);
}

char	**solve_quick(t_ps *ps)
{
	int	size;
	int	i;
	int	n;

	sort_list(ps);
	size = get_sortsize(ps->list_len);
	i = 0;
	n = ps->list_len / size + ((ps->list_len % size) > 0);
	while (i < n)
	{
		divide_stack(ps, size * i, size * (i + 1));
		sort_divided(ps, i * size);
		i++;
	}
	return (ps->ans);
}