/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:42:02 by mabois            #+#    #+#             */
/*   Updated: 2020/04/24 10:42:03 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_argv_input(t_piles *piles)
{
	int i;
	int j;

	i = -1;
	while (++i < piles->capacity)
	{
		j = i;
		while (++j < piles->capacity)
			if (piles->a[i] == piles->a[j])
				ft_exit(piles);
	}
}
