#include "checker.h"

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define RESET	"\033[m"

void	output_ko(bool f)
{
	if (f)
		ft_putstr_fd(RED, 1);
	ft_putendl_fd("KO", 1);
	if (f)
		ft_putstr_fd(RESET, 1);
	return ;
}

void	output_ok(bool f)
{
	if (f)
		ft_putstr_fd(GREEN, 1);
	ft_putendl_fd("OK", 1);
	if (f)
		ft_putstr_fd(RESET, 1);
	return ;
}
