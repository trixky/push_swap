/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:44:26 by mabois            #+#    #+#             */
/*   Updated: 2020/04/24 10:44:27 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_piles(t_piles *piles)
{
	if (piles != NULL)
	{
		ft_free(piles->a);
		ft_free(piles->b);
		ft_free(piles->a_temp);
		ft_free(piles->b_temp);
	}
}

void	ft_exit(t_piles *piles)
{
	ft_free_piles(piles);
	ft_putstr_fd(STDERR_FILENO, "Error\n");
	exit(EXIT_FAILURE);
}
