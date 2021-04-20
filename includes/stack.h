#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "./libft/libft.h"
typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				val;
}	t_stack;

t_stack	**create_stack(char **argv, t_stack **top);
void	print_stack(t_stack **top);
void	free_stack(t_stack **top);

#endif