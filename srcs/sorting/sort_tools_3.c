/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:43:28 by mabois            #+#    #+#             */
/*   Updated: 2020/04/24 10:43:30 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_smallest_index(t_piles *piles, const int pile)
{
	int	i;
	int smallest;

	i = -1;
	smallest = 0;
	while (++i < (pile == PILE_A ? piles->a_len : piles->b_len))
		if ((pile == PILE_A ? piles->a[i] : piles->b[i]) <
		(pile == PILE_A ? piles->a[smallest] : piles->b[smallest]))
			smallest = i;
	return (smallest);
}

int		ft_find_greatest_index(t_piles *piles, const int pile)
{
	int	i;
	int greatest;

	i = -1;
	greatest = 0;
	while (++i < (pile == PILE_A ? piles->a_len : piles->b_len))
		if ((pile == PILE_A ? piles->a[i] : piles->b[i]) >
		(pile == PILE_A ? piles->a[greatest] : piles->b[greatest]))
			greatest = i;
	return (greatest);
}
