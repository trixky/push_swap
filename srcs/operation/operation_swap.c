/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:41:50 by mabois            #+#    #+#             */
/*   Updated: 2020/04/24 10:41:52 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operation_swap_sa(t_piles *piles)
{
	if (piles->a_len > 2)
		ft_swap_int(&piles->a[0], &piles->a[1]);
	piles->nbr_operation++;
	if (!piles->silence_mod)
	{
		ft_putstr_fd(STDOUT_FILENO, "sa\n");
		ft_vn_activate(piles);
	}
}

void	ft_operation_swap_sb(t_piles *piles)
{
	if (piles->b_len > 2)
		ft_swap_int(&piles->b[0], &piles->b[1]);
	piles->nbr_operation++;
	if (!piles->silence_mod)
	{
		ft_putstr_fd(STDOUT_FILENO, "sb\n");
		ft_vn_activate(piles);
	}
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
	{
		ft_putstr_fd(STDOUT_FILENO, "ss\n");
		ft_vn_activate(piles);
	}
}
