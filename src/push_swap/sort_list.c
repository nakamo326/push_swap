#include "push_swap.h"

static int	*create_unsorted(t_stack **s, int *listlen)
{
	int		*list;
	t_stack	*s_ptr;
	int		i;

	*listlen = get_stacklen(s);
	list = malloc(sizeof(int) * *listlen);
	if (list == NULL)
		return (NULL);
	i = 0;
	s_ptr = *s;
	while (i < *listlen)
	{
		list[i] = s_ptr->val;
		i++;
		s_ptr = s_ptr->next;
	}
	return (list);
}

int	*sort_list(t_stack **s, int	*list)
{
	int	listlen;
	int	i;
	int	j;
	int	tmp;

	list = create_unsorted(s, &listlen);
	if (!list)
		return (NULL);
	i = 0;
	while (i < listlen)
	{
		j = i + 1;
		while (j < listlen)
		{
			if (list[i] > list[j])
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (list);
}
