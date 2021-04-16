#include "checker.h"

static bool	is_valid_arg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		if (!(ft_isdigit(argv[i][j]) || argv[i][j] == '-'))
			return (false);
		j++;
		while(argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		exit(EXIT_FAILURE);
	if (!is_valid_arg(argv))
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}