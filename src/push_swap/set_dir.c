#include "push_swap.h"

static int	*mark_target(t_ps *ps, int size, int *list)
{
	int		i;
	t_stack	*s;

	i = 0;
	s = *ps->a;
	while (i < ps->list_len)
	{
		if ((s->val <= ps->list[size - 1]))
			list[i] = 1;
		s = s->next;
		i++;
	}
	return (list);
}

t_op	set_dir(t_ps *ps, int size)
{
	int	*list;
	int	first;
	int	second;
	int	i;

	list = calloc(ps->list_len, sizeof(int));
	list = mark_target(ps, size, list);
	i = 0;
	first = 0;
	while (i < size)
	{
		first += list[i];
		i++;
	}
	second = 0;
	while (i < ps->list_len)
	{
		second += list[i];
		i++;
	}
	if (first <= second)
		return (ra);
	return (ra);//rra
}
