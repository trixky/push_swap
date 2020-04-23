#include "push_swap.h"

int		ft_have_option(int option, t_piles *piles)
{
	return ((piles->options / option) % 10 != 0);
}

void	ft_vn_activate(t_piles *piles)
{
	if ((piles->options / OPTION_N) % 10 != 0)
	{
		piles->time++;
		if (ft_have_option(OPTION_C, piles))
			write(1, KCYN, ft_strlen(KCYN));
		write(STDOUT_FILENO, "\t", 1);
		ft_putnbr(piles->time);
		write(STDOUT_FILENO, "\n", 1);
		if (ft_have_option(OPTION_C, piles))
			write(1, KNRM, ft_strlen(KNRM));
	}
	if ((piles->options / OPTION_V) % 10 != 0)
	{
		ft_show_piles(piles);
	}
}

int		ft_check_double_option(int option, int options, t_piles *piles)
{
	if (option == OPTION_V && ((options / OPTION_V) % 10 != 0))
		ft_exit(piles);
	if (option == OPTION_C && ((options / OPTION_C) % 10 != 0))
		ft_exit(piles);
	if (option == OPTION_H && ((options / OPTION_H) % 10 != 0))
		ft_exit(piles);
	if (option == OPTION_N && ((options / OPTION_N) % 10 != 0))
		ft_exit(piles);
	if (option == OPTION_F && ((options / OPTION_F) % 10 != 0))
		ft_exit(piles);
	return (option);
}

int		ft_check_option(int argc, char **argv, int *file_name, t_piles *piles)
{
	int i;
	int max_option;
	int	options;

	i = 0;
	max_option = 6;
	options = 0;
	while (++i <= max_option && i < argc)
	{
		if (ft_strlen(argv[i]) == 2 && argv[i][0] == '-')
		{
			if (argv[i][1] == 'v')
				options += ft_check_double_option(OPTION_V, options, piles);
			else if (argv[i][1] == 'c')
				options += ft_check_double_option(OPTION_C, options, piles);
			else if (argv[i][1] == 'h')
				options += ft_check_double_option(OPTION_H, options, piles);
			else if (argv[i][1] == 'n')
				options += ft_check_double_option(OPTION_N, options, piles);
			else if (argv[i][1] == 'f' && argc > i + 1)
			{
				options += ft_check_double_option(OPTION_F, options, piles);
				*file_name = ++i;
			}
			else
				break ;
		}
		else
			break ;
	}
	if (*file_name != 0 && i < argc)
		ft_exit(piles);
	return (options);
}

int		ft_options_number(int options)
{
	int	options_number;

	options_number = 0;
	if ((options / OPTION_V) % 10 != 0)
		options_number++;
	if ((options / OPTION_C) % 10 != 0)
		options_number++;
	if ((options / OPTION_H) % 10 != 0)
		options_number++;
	if ((options / OPTION_N) % 10 != 0)
		options_number++;
	if ((options / OPTION_F) % 10 != 0)
		options_number += 2;
	return (options_number);
}