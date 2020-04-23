#include "push_swap.h"

void	ft_operation_push_pa(t_piles *piles)
{
	int i;
	
	if (piles->b_len > 0)
	{
		i = piles->capacity;
		while (--i > 0)
			piles->a[i] = piles->a[i - 1];
		piles->a[0] = piles->b[0];
		piles->a_len++;
		i = -1;
		while (++i < piles->capacity - 1)
			piles->b[i] = piles->b[i + 1];
		piles->b_len--;
	}
	piles->nbr_operation++;
	if (!piles->silence_mod)
	{
		ft_putstr_fd(STDOUT_FILENO, "pa\n");
		ft_vn_activate(piles);
	}
}

void	ft_operation_push_pb(t_piles *piles)
{
	int i;
	
	if (piles->a_len > 0)
	{
		i = piles->capacity;
		while (--i > 0)
			piles->b[i] = piles->b[i - 1];
		piles->b[0] = piles->a[0];
		piles->b_len++;
		i = -1;
		while (++i < piles->capacity - 1)
			piles->a[i] = piles->a[i + 1];
		piles->a_len--;
	}
	piles->nbr_operation++;
	if (!piles->silence_mod)
	{
		ft_putstr_fd(STDOUT_FILENO, "pb\n");
		ft_vn_activate(piles);
	}
}
