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
t_stack	*search_minimum_elm(t_stack **a);
t_dir	search_shortest(t_dir *dir, t_stack **top, t_stack *minimum);
int		*sort_list(t_stack **s, int	*list);
t_op	*solve_quick(t_ps *ps);
t_op	*pb_mininum(t_ps *ps);
t_op	*solve_two(t_ps *ps);
t_op	*solve_three(t_stack **top, t_ps *ps);
t_op	*solve_four(t_ps *ps);
t_op	*solve_five(t_ps *ps);
t_op	*solve_six(t_ps *ps);
t_op	*record_do(t_op op, t_ps *ps);
bool	merge_operation(t_ps *ps);
bool	is_able_merge(t_op op, t_op next);
bool	is_able_delete(t_op op, t_op next);
t_op	*convert_rr(t_op *ans, int i);
t_op	*delete_pp(t_op *ans, int i);
void	output_answer(t_op *ans);

#endif