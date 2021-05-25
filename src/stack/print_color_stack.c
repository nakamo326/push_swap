#include "stack.h"

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"
#define RESET	"\033[m"

static void put_colorval(int val)
{
	ft_putstr_fd(BLUE, 2);
	ft_putnbr_fd(val, 2);
	ft_putstr_fd(RESET, 2);
}

//s ...top two, p ...top one, rr ... top one, r ... last one

static t_stack	*put_first_two(t_stack **s, t_op op)
{
	t_stack	*s_ptr;

	s_ptr = *s;
	if (op == sa || op == sb || op == ss || op == pa || op == pb
		|| op == rra || op == rrb || op == rrr)
		put_colorval(s_ptr->val);
	else
		ft_putnbr_fd(s_ptr->val, 2);
	if (s_ptr->next != *s)
		ft_putstr_fd(", ", 2);
	s_ptr = s_ptr->next;
	if (s_ptr == *s)
		return (NULL);
	if (op == sa || op == sb || op == ss)
		put_colorval(s_ptr->val);
	else
		ft_putnbr_fd(s_ptr->val, 2);
	if (s_ptr->next != *s)
		ft_putstr_fd(", ", 2);
	if (s_ptr->next == *s)
		return (NULL);
	return (s_ptr->next);
}

static void	put_lastval(int val, t_op op)
{
	if (op == ra || op == rb || op == rr)
		put_colorval(val);
	else
		ft_putnbr_fd(val, 2);
	return ;
}

static void	print_color_stack(t_stack **s, t_op op)
{
	t_stack *s_ptr;

	ft_putchar_fd('[', 2);
	s_ptr = put_first_two(s, op);
	while (s_ptr)
	{
		if (s_ptr->next == *s)
			put_lastval(s_ptr->val, op);
		else
			ft_putnbr_fd(s_ptr->val, 2);
		if (s_ptr->next != *s)
			ft_putstr_fd(", ", 2);
		s_ptr = s_ptr->next;
		if (s_ptr == *s)
			break ;
	}
	ft_putstr_fd("]\n", 2);
}

void	print_color_stacks(t_stack **a, t_stack **b, t_op op)
{
	if (op == sa || op == ss || op == pa || op == ra || op == rr
		|| op == rra || op == rrr)
		print_color_stack(a, op);
	else
		print_stack(a);
	if (op == sb || op == ss || op == pb || op == rb || op == rr
		|| op == rrb || op == rrr)
		print_color_stack(b, op);
	else
		print_stack(b);
	return ;
}
