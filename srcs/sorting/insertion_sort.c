/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:42:58 by mabois            #+#    #+#             */
/*   Updated: 2020/04/24 10:42:59 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_insertion_sort_with_brute_force(t_piles *piles)
{
	while (piles->a_len > 5)
		ft_best_move(piles);
	ft_rotate_sort_pile(piles, PILE_B);
	ft_brute_force_sort(piles);
	ft_smart_push_pa_rra(piles);
	ft_rotate_sort_pile(piles, PILE_A);
}

void	ft_insertion_sort_without_brute_force(t_piles *piles)
{
	while (piles->a_len != 0)
		ft_best_move(piles);
	ft_rotate_sort_pile(piles, PILE_B);
	while (piles->b_len != 0)
		ft_operation_push_pa(piles);
}

void	ft_insertion_sort(t_piles *piles)
{
	if (piles->capacity < 50)
		ft_insertion_sort_with_brute_force(piles);
	else
		ft_insertion_sort_without_brute_force(piles);
}
