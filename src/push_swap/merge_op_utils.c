#include "push_swap.h"

t_op	*convert_rr(t_op *ans, int i)
{
	ans[i] = rr;
	i++;
	while (ans[i + 1] != err)
	{
		ans[i] = ans[i + 1];
		i++;
	}
	ans[i] = err;
	return (ans);
}

t_op	*convert_rrr(t_op *ans, int i)
{
	ans[i] = rrr;
	i++;
	while (ans[i + 1] != err)
	{
		ans[i] = ans[i + 1];
		i++;
	}
	ans[i] = err;
	return (ans);
}

t_op	*delete_pp(t_op *ans, int i)
{
	while (ans[i + 2] != err)
	{
		ans[i] = ans[i + 2];
		ans[i + 2] = err;
		i++;
	}
	ans[i] = err;
	return (ans);
}

t_op	*merge_spps(t_op *ans, int *index)
{
	int	i;

	i = *index;
	ans[i] = pb;
	ans[i + 1] = pb;
	if (ans[i + 3] == sa)
	{
		ans[i + 2] = ss;
		i += 3;
	}
	else
		i += 2;
	*index = i - 1;
	while (ans[i + 1] != err)
	{
		ans[i] = ans[i + 1];
		i++;
	}
	ans[i] = err;
	return (ans);
}
