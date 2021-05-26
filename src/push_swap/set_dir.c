#include "push_swap.h"

static int	*mark_target_a(t_stack **a, int *s_list, int s_len, int size)
{
	int		*mark_list;
	int		i;
	t_stack	*s;

	mark_list = ft_calloc(s_len, sizeof(int));
	if (!s_list || !mark_list)
		return (NULL);
	i = 0;
	s = *a;
	while (i < s_len)
	{
		if (s->val <= s_list[size - 1])
			mark_list[i] = 1;
		s = s->next;
		i++;
	}
	return (mark_list);
}

t_op	set_dir_a(t_ps *ps, int size)
{
	int	*sorted_list;
	int	*mark_list;
	int	i;
	int	sum[2];

	sorted_list = NULL;
	sorted_list = sort_list(ps->a, sorted_list);
	mark_list = mark_target_a(ps->a, sorted_list, get_stacklen(ps->a), size);
	if (!sorted_list || !mark_list)
		return (err);
	i = 0;
	sum[0] = 0;
	while (i < size)
		sum[0] += mark_list[i++];
	sum[1] = 0;
	while (i < ps->list_len)
		sum[1] += mark_list[i++];
	if (sum[0] <= sum[1])
		return (rra);
	return (ra);
}

static int	*mark_target_b(t_stack **b, int *s_list, int s_len, int m)
{
	int		*mark_list;
	t_stack	*s;
	int		i;

	mark_list = ft_calloc(s_len, sizeof(int));
	if (!s_list || !mark_list)
		return (NULL);
	s = *b;
	i = 0;
	while (i < s_len)
	{
		if (s->val >= s_list[m])
			mark_list[i] = 1;
		s = s->next;
		i++;
	}
	return (mark_list);
}

t_op	set_dir_b(t_stack **b, int m, int s_len)
{
	int	*sorted_list;
	int	*mark_list;
	int	i;
	int	sum[2];

	sorted_list = NULL;
	sorted_list = sort_list(b, sorted_list);
	mark_list = mark_target_b(b, sorted_list, s_len, m);
	if (!sorted_list || !mark_list)
		return (err);
	i = 0;
	sum[0] = 0;
	while (i < m)
		sum[0] += mark_list[i++];
	sum[1] = 0;
	while (i < s_len)
		sum[1] += mark_list[i++];
	if (sum[0] <= sum[1])
		return (rrb);
	return (rb);
}
