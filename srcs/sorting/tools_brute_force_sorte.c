/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_brute_force_sorte.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:44:02 by mabois            #+#    #+#             */
/*   Updated: 2020/04/24 10:44:03 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_brute_force_show(t_piles *piles)
{
	int i;

	i = -1;
	ft_putstr_fd(STDOUT_FILENO, "== show brute foce array ==\n");
	while (++i < BRUT_FORCE_ARRAY_SIZE)
	{
		ft_putnbr(piles->brute_force_array[i]);
		ft_putchar_fd(STDOUT_FILENO, '\t');
		ft_putnbr(piles->brute_force_array_save[i]);
		ft_putchar_fd(STDOUT_FILENO, '\n');
	}
}

int		ft_brute_force_array_size(t_piles *piles)
{
	int i;

	i = -1;
	while (++i < BRUT_FORCE_ARRAY_SIZE &&
			piles->brute_force_array[i] != NOTHING)
		continue;
	return (i);
}

int		ft_brute_force_array_size_save(t_piles *piles)
{
	int i;

	i = -1;
	if (piles->brute_force_array_save[0] == START_VALUE)
		return (INT_MAX);
	while (++i < BRUT_FORCE_ARRAY_SIZE &&
			piles->brute_force_array_save[i] != NOTHING)
		continue;
	return (i);
}

void	ft_brute_force_save(t_piles *piles)
{
	int i;

	i = -1;
	while (++i < BRUT_FORCE_ARRAY_SIZE)
		piles->brute_force_array_save[i] = piles->brute_force_array[i];
}
