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
	int		list_len;
	t_op	*ans;
	int		ans_size;
	int		i;
}	t_ps;

t_ps	*init_ps(void);
t_op	*solver_ent(t_ps *ps);
t_op	*record_do(t_op op, t_ps *ps);
int		*sort_list(t_stack **s, int	*list);
t_op	*pb_mininum(t_ps *ps);
t_op	*solve_two(t_ps *ps);
t_op	*solve_three(t_stack **top, t_ps *ps);
t_op	*solve_four(t_ps *ps);
t_op	*solve_five(t_ps *ps);
t_op	*solve_six(t_ps *ps);
t_op	*solve_quick(t_ps *ps);
void	set_first(t_ps *ps, int size);
t_op	set_dir_a(t_ps *ps, int size);
t_op	set_dir_b(t_stack **b, int m, int s_len);
bool	merge_operation(t_ps *ps);
t_op	*convert_rr(t_op *ans, int i);
t_op	*convert_rrr(t_op *ans, int i);
t_op	*delete_pp(t_op *ans, int i);
void	output_answer(t_op *ans);

#endif