#ifndef STACK_H
# define STACK_H

struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				val;
}	t_stack;

#endif