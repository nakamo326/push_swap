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

typedef struct s_ps
{
	t_stack	**a;
	t_stack	**b;
	int		*list;
}	t_ps;

char	**solver_ent(t_stack **a, t_stack **b);
char	**solver(t_stack **a, t_stack **b);
char	**pb_mininum(t_stack **a, t_stack **b, char **ans);
char	**solve_two(t_stack **top, char **ans);
char	**solve_three(t_stack **top, char **ans);
char	**solve_four(t_stack **a, t_stack **b, char **ans);
char	**solve_five(t_stack **a, t_stack **b, char **ans);
char	**solve_six(t_stack **a, t_stack **b, char **ans);
char	**record_do(t_op op, char **ans, t_stack **a, t_stack **b);
void	output_answer(char	**ans);

#endif