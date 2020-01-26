#include "push_swap.h"

int		ft_operation_rotate_ra(t_piles *piles)
{
	int	i;
	int	save_first;
	
	if (piles->a_len > 1)
	{
		i = -1;
		save_first = piles->a[0];
		while (++i < piles->a_len - 1)
			piles->a[i] = piles->a[i + 1];
		piles->a[piles->a_len - 1] = save_first;
	}
	piles->nbr_operation++;
		if (!piles->silence_mod)
	ft_putstr_fd(STDOUT_FILENO, "ra\n");
	return (1);
}

int		ft_operation_rotate_rb(t_piles *piles)
{
	int	i;
	int	save_first;
	
	if (piles->b_len > 1)
	{
		i = -1;
		save_first = piles->b[0];
		while (++i < piles->b_len - 1)
			piles->b[i] = piles->b[i + 1];
		piles->b[piles->b_len - 1] = save_first;
	}
	piles->nbr_operation++;
		if (!piles->silence_mod)
	ft_putstr_fd(STDOUT_FILENO, "rb\n");
	return (1);
}

int		ft_operation_rotate_rr(t_piles *piles)
{
	int initial_silent_mod;
	
	initial_silent_mod = piles->silence_mod;
	piles->silence_mod = TRUE;
	ft_operation_rotate_ra(piles);
	ft_operation_rotate_rb(piles);
	piles->silence_mod = initial_silent_mod;
	piles->nbr_operation--;
	if (!piles->silence_mod)
		ft_putstr_fd(STDOUT_FILENO, "rr\n");
	return (1);
}
