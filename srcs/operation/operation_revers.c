/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_revers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:41:29 by mabois            #+#    #+#             */
/*   Updated: 2020/04/24 10:41:32 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operation_revers_rra(t_piles *piles)
{
	int	i;
	int	save_first;

	if (piles->a_len > 1)
	{
		i = piles->capacity;
		save_first = piles->a[piles->a_len - 1];
		while (--i > 0)
			piles->a[i] = piles->a[i - 1];
		piles->a[0] = save_first;
	}
	piles->nbr_operation++;
	if (!piles->silence_mod)
	{
		ft_putstr_fd(STDOUT_FILENO, "rra\n");
		ft_vn_activate(piles);
	}
}

void	ft_operation_revers_rrb(t_piles *piles)
{
	int	i;
	int	save_first;

	if (piles->b_len > 1)
	{
		i = piles->capacity;
		save_first = piles->b[piles->b_len - 1];
		while (--i > 0)
			piles->b[i] = piles->b[i - 1];
		piles->b[0] = save_first;
	}
	piles->nbr_operation++;
	if (!piles->silence_mod)
	{
		ft_putstr_fd(STDOUT_FILENO, "rrb\n");
		ft_vn_activate(piles);
	}
}

void	ft_operation_revers_rrr(t_piles *piles)
{
	int initial_silent_mod;

	initial_silent_mod = piles->silence_mod;
	piles->silence_mod = TRUE;
	ft_operation_revers_rra(piles);
	ft_operation_revers_rrb(piles);
	piles->silence_mod = initial_silent_mod;
	piles->nbr_operation--;
	if (!piles->silence_mod)
	{
		ft_putstr_fd(STDOUT_FILENO, "rrr\n");
		ft_vn_activate(piles);
	}
}
