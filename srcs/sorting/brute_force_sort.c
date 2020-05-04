#include "push_swap.h"

int		ft_brute_force_test(t_piles *piles)
{
	int i;
	int	ret;

	i = -1;
	ft_start_test(piles, TRUE);
	while (++i < BRUT_FORCE_ARRAY_SIZE &&
			piles->brute_force_array[i] != NOTHING)
		if (piles->brute_force_array[i] == SA)
			ft_operation_swap_sa(piles);
		else if (piles->brute_force_array[i] == RA)
			ft_operation_rotate_ra(piles);
		else if (piles->brute_force_array[i] == RRA)
			ft_operation_revers_rra(piles);
	ret = ft_is_sorted_down(piles, PILE_A, TRUE);
	ft_stop_test(piles, FALSE);
	return (ret);
}

void	ft_brute_force_application(t_piles *piles)
{
	int i;

	i = -1;
	while (++i < BRUT_FORCE_ARRAY_SIZE &&
			piles->brute_force_array_save[i] != NOTHING)
	{
		if (piles->brute_force_array_save[i] == SA)
			ft_operation_swap_sa(piles);
		else if (piles->brute_force_array_save[i] == RA)
			ft_operation_rotate_ra(piles);
		else if (piles->brute_force_array_save[i] == RRA)
			ft_operation_revers_rra(piles);
	}
}

void	ft_recursive(t_piles *piles, const int deep)
{
	int i;

	i = 0;
	while (++i <= INSTRUCTION_NBR)
	{
		piles->brute_force_array[deep] = i;
		if (ft_brute_force_array_size(piles) <
				ft_brute_force_array_size_save(piles) &&
				ft_brute_force_test(piles))
		{
			ft_brute_force_save(piles);
			piles->brute_force_array[deep] = NOTHING;
			return ;
		}
		if (deep < BRUT_FORCE_ARRAY_SIZE - 1)
			ft_recursive(piles, deep + 1);
	}
	piles->brute_force_array[deep] = NOTHING;
}

void	ft_brute_force_sort(t_piles *piles)
{
	ft_recursive(piles, 0);
	ft_brute_force_application(piles);
}
