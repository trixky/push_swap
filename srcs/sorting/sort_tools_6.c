#include "push_swap.h"

int		ft_find_smallest_value(t_piles *piles, const int pile)
{
	int	i;
	int smallest;

	i = -1;
	smallest = piles->b[0];
	while (++i < (pile == PILE_A ? piles->a_len : piles->b_len))
		if ((pile == PILE_A ? piles->a[i] : piles->b[i]) < smallest)
			smallest = (pile == PILE_A ? piles->a[i] : piles->b[i]);
	return (smallest);
}

int		ft_find_greatest_value(t_piles *piles, const int pile)
{
	int	i;
	int greatest;

	i = -1;
	greatest = piles->b[0];
	while (++i < (pile == PILE_A ? piles->a_len : piles->b_len))
		if ((pile == PILE_A ? piles->a[i] : piles->b[i]) > greatest)
			greatest = (pile == PILE_A ? piles->a[i] : piles->b[i]);
	return (greatest);
}

void	ft_operation_rotate_ra_x_time(t_piles *piles, const int time)
{
	int i;

	i = -1;
	while (++i < time)
		ft_operation_rotate_ra(piles);
}

void	ft_operation_rotate_rb_x_time(t_piles *piles, const int time)
{
	int i;

	i = -1;
	while (++i < time)
		ft_operation_rotate_rb(piles);
}
