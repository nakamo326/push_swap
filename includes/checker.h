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

void	output_ko(void);
void	output_ok(void);
int		output_error(t_stack **a, t_stack **b);

void	run_operation(t_stack **a, t_stack **b);
void	check_result(t_stack **a, t_stack **b);

#endif