#include "checker.h"

int	output_error(void)
{
	ft_putendl_fd("Error", 2);
	return (EXIT_FAILURE);
}

void	output_ko(void)
{
	ft_putendl_fd("KO", 1);
	return ;
}

void	output_ok(void)
{
	ft_putendl_fd("OK", 1);
	return ;
}
