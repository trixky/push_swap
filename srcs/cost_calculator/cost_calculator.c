#include "push_swap.h"

void	ft_start_test(t_piles *piles, const int silence_mod)
{
	int	i;

	i = -1;
	while (++i < piles->capacity)
	{
		piles->a_temp[i] = piles->a[i];
		piles->b_temp[i] = piles->b[i];
	}
	piles->a_len_temp = piles->a_len;
	piles->b_len_temp = piles->b_len;
	piles->nbr_operation_temp = piles->nbr_operation;
	piles->silence_mod = silence_mod;
}

int		ft_stop_test(t_piles *piles, const int silence_mod)
{
	int	i;
	int	cost;

	i = -1;
	cost = piles->nbr_operation - piles->nbr_operation_temp;
	while (++i < piles->capacity)
	{
		piles->a[i] = piles->a_temp[i];
		piles->b[i] = piles->b_temp[i];
	}
	piles->a_len = piles->a_len_temp;
	piles->b_len = piles->b_len_temp;
	piles->nbr_operation = piles->nbr_operation_temp;
	piles->silence_mod = silence_mod;
	return (cost);
}
