#include "push_swap.h"

void	ft_init_brute_force_array(t_piles *piles)
{
	int	i;
	
	i = -1;
	while (++i < BRUT_FORCE_ARRAY_SIZE)
	{
		piles->brute_force_array[i] = NOTHING;
		piles->brute_force_array_save[i] = START_VALUE;
	}
}

void	ft_init(t_piles *piles)
{
	piles->time = 0;
	piles->silence_mod = FALSE;
	piles->capacity = 0;
	piles->a = NULL;
	piles->b = NULL;
	piles->a_temp = NULL;
	piles->b_temp = NULL;
	piles->a_len = 0;
	piles->b_len = 0;
	piles->a_len_temp = 0;
	piles->b_len_temp = 0;
	piles->nbr_operation = 0;
	piles->nbr_operation_temp = 0;
	ft_init_brute_force_array(piles);
}