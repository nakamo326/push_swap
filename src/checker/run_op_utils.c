#include "checker.h"

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define RESET	"\033[m"

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
	if (op == sa || op == sb || op == ss)
		ft_putstr_fd(BLUE, 2);
	else if (op == pa || op == pb)
		ft_putstr_fd(YELLOW, 2);
	else if (op == ra || op == rb || op == rr)
		ft_putstr_fd(GREEN, 2);
	else if (op == rra || op == rrb || op == rrr)
		ft_putstr_fd(RED, 2);
	ft_putendl_fd(convert_op(op), 2);
	ft_putstr_fd(RESET, 2);
}

void	print_stacks(t_stack **a, t_stack **b, bool *f, t_op op)
{
	if (f[2] == true)
		clear_output(op);
	if (f[1] == false)
	{
		print_stack(a);
		print_stack(b);
	}
	else
		print_color_stacks(a, b, op);
	return ;
}

void	output_result(int i, bool *f)
{
	ft_putstr_fd("score is ... ", 2);
	if (f[1] == true)
		ft_putstr_fd(BLUE, 2);
	ft_putnbr_fd(i, 2);
	if (f[1] == true)
		ft_putstr_fd(RESET, 2);
	ft_putendl_fd("", 2);
	return ;
}
