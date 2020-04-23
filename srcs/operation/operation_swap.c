#include "push_swap.h"

void	ft_operation_swap_sa(t_piles *piles)
{
	if (piles->a_len > 2)
		ft_swap_int(&piles->a[0], &piles->a[1]);
	piles->nbr_operation++;
		if (!piles->silence_mod)
	ft_putstr_fd(STDOUT_FILENO, "sa\n");
}

void	ft_operation_swap_sb(t_piles *piles)
{
	if (piles->b_len > 2)
		ft_swap_int(&piles->b[0], &piles->b[1]);
	piles->nbr_operation++;
		if (!piles->silence_mod)
	ft_putstr_fd(STDOUT_FILENO, "sb\n");
}

void	ft_operation_swap_ss(t_piles *piles)
{
	int initial_silent_mod;
	
	initial_silent_mod = piles->silence_mod;
	piles->silence_mod = TRUE;
	ft_operation_swap_sa(piles);
	ft_operation_swap_sb(piles);
	piles->silence_mod = initial_silent_mod;	
	piles->nbr_operation--;
	if (!piles->silence_mod)
		ft_putstr_fd(STDOUT_FILENO, "ss\n");
}