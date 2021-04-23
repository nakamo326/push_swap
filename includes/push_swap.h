#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "stack.h"
# include "./libft/libft.h"

typedef enum e_dir
{
	NEXT,
	PREV
}	t_dir;

char	**solver_ent(t_stack **a_top, t_stack **b_top);
char	**solver(t_stack **a_top, t_stack **b_top);
char	**pb_mininum(t_stack **a_top, t_stack **b_top, char **ans);
char	**solve_two(t_stack **top, char **ans);
char	**solve_three(t_stack **top, char **ans);
char	**solve_four(t_stack **a_top, t_stack **b_top, char **ans);
char	**solve_five(t_stack **a_top, t_stack **b_top, char **ans);
char	**record_do(t_op op, char **ans, t_stack **a_top, t_stack **b_top);
void	output_answer(char	**ans);

#endif