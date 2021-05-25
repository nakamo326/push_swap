#include "checker.h"

void	output_current(t_stack **a, t_stack **b)
{
	ft_putstr_fd("\033[H", 1);
	ft_putstr_fd("\033[0J", 1);
	ft_putendl_fd("current stacks are ...", 2);
	print_stack(a);
	print_stack(b);

}

void	clear_output(t_op op)
{
	ft_putstr_fd("\033[H", 1);
	ft_putstr_fd("\033[0J", 1);
	ft_putstr_fd("last operation is ", 2);
	ft_putendl_fd(convert_op(op), 2);
}
