#include "push_swap.h"

void	set_first(t_ps *ps, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (((*ps->a)->val <= ps->list[size - 1]))
		{
			ps->ans = record_do(pb, ps);
			i++;
		}
		else
			ps->ans = record_do(ra, ps);
	}
}
