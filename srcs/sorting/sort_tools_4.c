#include "push_swap.h"

int		ft_find_below_b(int nbr, t_piles *piles)
{
	int i;
	int below;

	i = -1;
	below = ft_find_smallest_index(piles, PILE_B);
	while (++i < piles->b_len)
		if (piles->b[i] > piles->b[below] && piles->b[i] < nbr)
			below = i;
	if (piles->b[below] > nbr)
		below = ft_find_greatest_index(piles, PILE_B);
	return (below);
}

int		ft_find_above_a(int nbr, t_piles *piles)
{
	int i;
	int above;

	i = -1;
	above = ft_find_greatest_index(piles, PILE_A);
	while (++i < piles->a_len)
		if (piles->a[i] < piles->a[above] && piles->a[i] > nbr)
			above = i;
	if (piles->a[above] < nbr)
		above = ft_find_smallest_index(piles, PILE_A);
	return (above);
}

void	ft_rotate_sort_pile(t_piles *piles, const int pile)
{
	if (ft_find_greatest_index(piles, pile) <
			(pile == PILE_A ? piles->a_len : piles->b_len) / 2)
		pile == PILE_A ? ft_operation_rotate_ra_x_time(piles,
		ft_find_smallest_index(piles, pile)) :
		ft_operation_rotate_rb_x_time(piles,
		ft_find_greatest_index(piles, pile));
	else
		pile == PILE_A ? ft_operation_revers_rra_x_time(piles,
		piles->a_len - ft_find_smallest_index(piles, pile)) :
		ft_operation_revers_rrb_x_time(piles, piles->b_len -
		ft_find_greatest_index(piles, pile));
}

void	ft_smart_push_pb_ra(int index, t_piles *piles)
{
	int first_expected;

	first_expected = ft_find_below_b(piles->a[index], piles);
	if (first_expected < piles->b_len / 2)
	{
		if (index < first_expected)
		{
			ft_operation_rotate_rr_x_time(piles, index);
			ft_operation_rotate_rb_x_time(piles, first_expected - index);
		}
		else
		{
			ft_operation_rotate_rr_x_time(piles, first_expected);
			ft_operation_rotate_ra_x_time(piles, index - first_expected);
		}
	}
	else
	{
		ft_operation_rotate_ra_x_time(piles, index);
		ft_operation_revers_rrb_x_time(piles, piles->b_len - first_expected);
	}
	ft_operation_push_pb(piles);
}
