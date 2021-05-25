#ifndef CHECKER_H
# define CHECKER_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "stack.h"
# include "get_next_line.h"
# include "./libft/libft.h"

void	output_ko(bool f);
void	output_ok(bool f);
int		output_error(t_stack **a, t_stack **b);

void	run_operation(t_stack **a, t_stack **b, bool *op);
void	clear_output(t_op op);
void	output_current(t_stack **a, t_stack **b);
void	check_result(t_stack **a, t_stack **b, bool f);
int		get_option(char **argv, bool *op_flag);

#endif