#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "stack.h"
# include "get_next_line.h"
# include "./libft/libft.h"

int		output_error(void);
void	output_ko(void);
void	output_ok(void);

void	check_result(t_stack **a_top, t_stack **b_top);

#endif