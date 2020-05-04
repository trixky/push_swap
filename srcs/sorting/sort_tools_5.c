#include "push_swap.h"

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
			ft_operation_revers_rrb_x_time(piles, piles->b_len -
			first_expected - (piles->a_len - index));
		}
		else
		{
			ft_operation_revers_rrr_x_time(piles, piles->b_len -
			first_expected);
			ft_operation_revers_rra_x_time(piles, piles->a_len - index -
			(piles->b_len - first_expected));
		}
	}
	ft_operation_push_pb(piles);
}

void	ft_best_move_norme_1(t_piles *piles, int *all)
{
	while (++all[0] < piles->a_len)
	{
		ft_start_test(piles, TRUE);
		ft_smart_push_pb_ra(all[0], piles);
		if ((all[1] = ft_stop_test(piles, FALSE)) < all[3])
		{
			all[2] = all[0];
			all[3] = all[1];
		}
		if (all[0] > all[3])
			break ;
	}
}

void	ft_best_move_norme_2(t_piles *piles, int *all)
{
	while (--all[0] >= 0)
	{
		ft_start_test(piles, TRUE);
		ft_smart_push_pb_rra(all[0], piles);
		if ((all[1] = ft_stop_test(piles, FALSE)) < all[5])
		{
			all[4] = all[0];
			all[5] = all[1];
		}
		if (piles->a_len - all[0] > all[5])
			break ;
	}
}

int		ft_best_move(t_piles *piles)
{
	int all[6];

	all[0] = -1;
	all[2] = 0;
	all[3] = INT_MAX;
	ft_best_move_norme_1(piles, all);
	all[0] = piles->a_len;
	all[4] = 0;
	all[5] = INT_MAX;
	ft_best_move_norme_2(piles, all);
	if (all[3] < all[5])
		ft_smart_push_pb_ra(all[2], piles);
	else
		ft_smart_push_pb_rra(all[4], piles);
	return (all[4]);
}
