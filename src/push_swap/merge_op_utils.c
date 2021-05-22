#include "push_swap.h"

bool	is_able_merge(char *op, char *next)
{
	if (!ft_strncmp(op, "ra", 3) && !ft_strncmp(next, "rb", 3))
		return (true);
	else if (!ft_strncmp(op, "rb", 3) && !ft_strncmp(next, "ra", 3))
		return (true);
	return (false);
}

bool	is_able_delete(char *op, char *next)
{
	if (!ft_strncmp(op, "pa", 3) && !ft_strncmp(next, "pb", 3))
		return (true);
	else if (!ft_strncmp(op, "pb", 3) && !ft_strncmp(next, "pa", 3))
		return (true);
	return (false);
}

char	**convert_rr(char **ans, int i)
{
	free(ans[i]);
	free(ans[i + 1]);
	ans[i] = ft_strdup("rr");
	if (ans[i] == NULL)
		return (NULL);
	i++;
	while (ans[i + 1] != NULL)
	{
		ans[i] = ans[i + 1];
		i++;
	}
	ans[i] = NULL;
	return (ans);
}

char	**delete_pp(char **ans, int i)
{
	free(ans[i]);
	free(ans[i + 1]);
	while (ans[i + 2] != NULL)
	{
		ans[i] = ans[i + 2];
		i++;
	}
	ans[i] = NULL;
	return (ans);
}
