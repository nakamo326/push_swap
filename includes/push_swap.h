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
	char	**ans;
	int		i;
}	t_ps;

t_ps	*init_ps(void);
char	**solver_ent(t_ps *ps);
char	**solver(t_stack **a, t_stack **b);
t_stack	*search_minimum_elm(t_stack **a);
t_dir	search_shortest(t_dir *dir, t_stack **top, t_stack *minimum);
int		*sort_list(t_stack **s, int	*list);
char	**solve_quick(t_ps *ps);
char	**pb_mininum(t_stack **a, t_stack **b, char **ans);
char	**solve_two(t_stack **top, char **ans);
char	**solve_three(t_stack **top, char **ans);
char	**solve_four(t_stack **a, t_stack **b, char **ans);
char	**solve_five(t_stack **a, t_stack **b, char **ans);
char	**solve_six(t_stack **a, t_stack **b, char **ans);
char	**record_do(t_op op, char **ans, t_stack **a, t_stack **b);
bool	merge_operation(t_ps *ps);
bool	is_able_merge(char *op, char *next);
bool	is_able_delete(char *op, char *next);
char	**convert_rr(char **ans, int i);
char	**delete_pp(char **ans, int i);
void	output_answer(char	**ans);

#endif