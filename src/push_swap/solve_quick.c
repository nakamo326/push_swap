#include "push_swap.h"
#include <stdio.h>

int	get_sortsize(int stacklen)
{
	if (stacklen <= 50)
		return (10);
	if (stacklen <= 100)
		return (25);
	if (stacklen <= 300)
		return (40);
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
	return (true);
}

int	check_toptwo(t_ps *ps, int i)
{
	if (*ps->a == NULL || i >= ps->list_len)
		return (i);
	if ((*ps->a)->val == ps->list[i])
	{
		ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
		i++;
		return (check_toptwo(ps, i));
	}
	else if ((*ps->a)->next->val == ps->list[i])
	{
		ps->ans = record_do(sa, ps->ans, ps->a, ps->b);
		ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
		i++;
		return (check_toptwo(ps, i));
	}
	return (i);
}

char	**sort_divided(t_ps *ps, int i)
{
	int	n;
	int	p;
	int	tmp;

	ft_putendl_fd("start sorting devided", 2);
	print_stack(ps->b);
	if ((*ps->b) == NULL)
		return (ps->ans);
	n = get_stacklen(ps->b) / 2;
	if (n == 1)
		n = get_stacklen(ps->b);
	n += i;
	p = 0;
	while (*(ps->b) != NULL && i + p < n && i < ps->list_len)
	{
		if ((*ps->b)->val >= ps->list[i] && (*ps->b)->val <= ps->list[n - 1])
		{
			ps->ans = record_do(pa, ps->ans, ps->a, ps->b);
			if ((*ps->a)->val == ps->list[i])
			{
				ps->ans = record_do(ra, ps->ans, ps->a, ps->b);
				i++;
				tmp = i;
				i = check_toptwo(ps, i);
				p -= i - tmp;
			}
			else
				p++;
			print_stack(ps->a);
		}
		else
			ps->ans = record_do(rb, ps->ans, ps->a, ps->b);
	}
	p = 0;
	while (p < n - i)
	{
		ps->ans = record_do(pb, ps->ans, ps->a, ps->b);
		p++;
	}
	return (sort_divided(ps, i));
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