#include "push_swap.h"



int main(int argc, char **argv)
{
	int 	file_name;
	int		options;
	t_piles	piles;
	
	ft_init(&piles);
	file_name = 0;
	options = ft_check_option(argc, argv, &file_name, &piles);
	piles.options = options;
	if (file_name == 0)
		ft_input_args(argc, argv, &piles, ft_options_number(options));
	else
		ft_input_args_file(file_name, &piles, argv);
	ft_check_argv_input(&piles);
	if (!ft_is_sorted_down(&piles, PILE_A, TRUE))
	{
		if (piles.capacity < 6)
			ft_brute_force_sort(&piles);
		else
			ft_insertion_sort(&piles);
	}
	// ft_show_piles(&piles);										/* show */
	ft_free_piles(&piles);
	return (EXIT_SUCCESS);
}