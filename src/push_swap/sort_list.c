#include "push_swap.h"

static bool	create_unsorted(t_ps *ps)
{
	t_stack	*s_ptr;
	int		i;

	ps->list_len = get_stacklen(ps->a);
	ps->list = malloc(sizeof(int) * ps->list_len);
	if (ps->list == NULL)
		return (false);
	i = 0;
	s_ptr = *ps->a;
	while (i < ps->list_len)
	{
		ps->list[i] = s_ptr->val;
		i++;
		s_ptr = s_ptr->next;
	}
	return (true);
}

bool	sort_list(t_ps *ps)
{
	int		i;
	int		j;
	int		tmp;

	if (!create_unsorted(ps))
		return (false);
	i = 0;
	while (i < ps->list_len)
	{
		j = i + 1;
		while (j < ps->list_len)
		{
			if (ps->list[i] > ps->list[j])
			{
				tmp = ps->list[i];
				ps->list[i] = ps->list[j];
				ps->list[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (true);
}