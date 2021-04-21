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

bool	solver(t_stack **a_top, t_stack **b_top);
char	**record_do(t_op op, char **ans, t_stack ***a_top, t_stack ***b_top);
void	output_answer(char	**ans);

#endif