/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:42:17 by mabois            #+#    #+#             */
/*   Updated: 2020/04/24 10:42:18 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_help(t_piles *piles)
{
	if (ft_have_option(OPTION_H, piles))
	{
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, "\t--- help section ---\n", 22);
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, "   -v : show piles\n", 19);
		write(STDOUT_FILENO, "   -c : color\n", 14);
		write(STDOUT_FILENO, "   -h : help\n", 13);
		write(STDOUT_FILENO, "   -n : move counter\n", 21);
		write(STDOUT_FILENO, "   -f : file entry\n", 19);
		write(STDOUT_FILENO,
		"        ( exemple : ./push_swap -f my_numbers.txt )\n", 53);
		write(STDOUT_FILENO, "\n", 1);
		ft_free_piles(piles);
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	int		file_name;
	int		options;
	t_piles	piles;

	ft_init(&piles);
	file_name = 0;
	options = ft_check_option(argc, argv, &file_name, &piles);
	piles.options = options;
	ft_help(&piles);
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
	ft_free_piles(&piles);
	return (EXIT_SUCCESS);
}
