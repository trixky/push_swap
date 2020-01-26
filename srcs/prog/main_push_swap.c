#include "push_swap.h"

int main(int argc, char **argv)
{
	t_piles	piles;
	
	ft_init(&piles);
	ft_input_args(argc, argv, &piles);
	ft_check_argv_input(&piles);
	// ft_show_piles(&piles);										/* show */
	ft_is_sorted_down(&piles, PILE_A, TRUE);
	if (piles.capacity < 6)
		ft_brute_force_sort(&piles);
	else
		ft_trixky_sort(&piles);
	// ft_show_piles(&piles);										/* show */
	// printf("nombre d'operation = %d\n", piles.nbr_operation);	/* show */
	// ft_is_sorted_down(&piles, PILE_A, FALSE);					/* show */
	ft_free_piles(&piles);
	return (EXIT_SUCCESS);
}