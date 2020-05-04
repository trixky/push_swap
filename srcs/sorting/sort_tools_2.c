#include "push_swap.h"

void	ft_operation_revers_rra_x_time(t_piles *piles, const int time)
{
	int i;

	i = -1;
	while (++i < time)
		ft_operation_revers_rra(piles);
}

void	ft_operation_revers_rrb_x_time(t_piles *piles, const int time)
{
	int i;

	i = -1;
	while (++i < time)
		ft_operation_revers_rrb(piles);
}

void	ft_operation_rotate_rr_x_time(t_piles *piles, const int time)
{
	int i;

	i = -1;
	while (++i < time)
		ft_operation_rotate_rr(piles);
}

void	ft_operation_revers_rrr_x_time(t_piles *piles, const int time)
{
	int i;

	i = -1;
	while (++i < time)
		ft_operation_revers_rrr(piles);
}
