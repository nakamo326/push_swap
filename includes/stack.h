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

typedef enum e_op
{
	err,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_op;

t_stack	**create_stack(char **argv, t_stack **top, int i);
t_stack	*create_newelm(int value);
t_stack	*add_top(t_stack **top, int value);
t_stack	*add_bottom(t_stack **top, int value);
void	print_stack(t_stack **top);
void	print_color_stacks(t_stack **a, t_stack **b, t_op op);
void	*free_stack(t_stack **top);
int		get_stacklen(t_stack **top);

bool	do_operation(char *op, t_stack **a, t_stack **b);
t_op	is_valid_op(char *line);
bool	swap(t_stack **top);
bool	push(t_stack **out_top, t_stack **in_top);
bool	rotate(t_stack **top);
bool	rev_rotate(t_stack **top);

#endif