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
	if (ft_find_greatest_index(piles, pile) < (pile == PILE_A ? piles->a_len : piles->b_len) / 2)
		pile == PILE_A ? ft_operation_rotate_ra_x_time(piles, ft_find_greatest_index(piles, pile)) : ft_operation_rotate_rb_x_time(piles, ft_find_greatest_index(piles, pile));
	else
		pile == PILE_A ? ft_operation_revers_rra_x_time(piles, piles->a_len - ft_find_greatest_index(piles, pile)) : ft_operation_revers_rrb_x_time(piles, piles->b_len - ft_find_greatest_index(piles, pile));
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
			ft_operation_rotate_rr_x_time(piles, first_expected);			/* echange pb ? */
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

void	ft_smart_push_pb_rra(int index, t_piles *piles)
{
	int first_expected;
	
	first_expected = ft_find_below_b(piles->a[index], piles);
	if (first_expected < piles->b_len / 2)
	{
		ft_operation_revers_rra_x_time(piles, piles->a_len - index);
		ft_operation_rotate_rb_x_time(piles, first_expected);
	}
	else
	{
		if (piles->a_len - index < piles->b_len - first_expected)
		{
			ft_operation_revers_rrr_x_time(piles, piles->a_len - index);
			ft_operation_revers_rrb_x_time(piles, piles->b_len - first_expected - (piles->a_len - index));
		}
		else
		{
			ft_operation_revers_rrr_x_time(piles, piles->b_len - first_expected);
			ft_operation_revers_rra_x_time(piles, piles->a_len - index - (piles->b_len - first_expected));
		}
	}
	ft_operation_push_pb(piles);
}

int		ft_best_move(t_piles *piles)
{
	int i;
	int ret;
	int	best_move_index_ra;
	int	best_move_cost_ra;
	int	best_move_index_rra;
	int	best_move_cost_rra;
	
	i = -1;
	best_move_index_ra = 0;
	best_move_cost_ra = INT_MAX;
	while (++i < piles->a_len)
	{
		ft_start_test(piles, TRUE);
		ft_smart_push_pb_ra(i, piles);
		if ((ret = ft_stop_test(piles, FALSE)) < best_move_cost_ra)
		{
			best_move_index_ra = i;	
			best_move_cost_ra = ret;
		}
		if (i > best_move_cost_ra)
			break;
	}
	i = piles->a_len;
	best_move_index_rra = 0;
	best_move_cost_rra = INT_MAX;
	while (--i >= 0)
	{
		ft_start_test(piles, TRUE);
		ft_smart_push_pb_rra(i, piles);
		if ((ret = ft_stop_test(piles, FALSE)) < best_move_cost_rra)
		{
			best_move_index_rra = i;	
			best_move_cost_rra = ret;
		}
		if (piles->a_len - i > best_move_cost_rra)
			break;
	}
	if (best_move_cost_ra < best_move_cost_rra)
		ft_smart_push_pb_ra(best_move_index_ra, piles);
	else
		ft_smart_push_pb_rra(best_move_index_rra, piles);
	return (best_move_index_rra);
}

void	ft_smart_push_pa_ra(t_piles *piles)
{
	while (piles->b_len > 0)
	{
		while (0 != ft_find_above_a(piles->b[0], piles))
			ft_operation_rotate_ra(piles);
		ft_operation_push_pa(piles);
	}
}

void	ft_smart_push_pa_rra(t_piles *piles)
{
	while (piles->b_len > 0)
	{
		while (0 != ft_find_above_a(piles->b[0], piles))
			ft_operation_revers_rra(piles);
		ft_operation_push_pa(piles);
	}
}

/* new */
void	ft_trixky_sort(t_piles *piles)
{
	// while (piles->a_len > 5)
	while (piles->a_len > 5)
		ft_best_move(piles);
	ft_rotate_sort_pile(piles, PILE_B);
	ft_brute_force_sort(piles);
	ft_show_piles(piles);
	// ft_smart_push_pa_ra(piles);
	ft_smart_push_pa_rra(piles);
}

// void	ft_trixky_sort(t_piles *piles)
// {
// 	// while (piles->a_len > 5)
// 	while (piles->a_len != 0)
// 		ft_best_move(piles);
// 	ft_rotate_sort_pile(piles, PILE_B);
// 	// ft_brute_force_sort(piles);
// 	// ft_show_piles(piles);
// 	// ft_smart_push_pa(piles);
// 	while (piles->b_len != 0)
// 		ft_operation_push_pa(piles);
// 	// while (piles->b_len != 0)
// 	// 	ft_smart_push_pa(piles);
// }