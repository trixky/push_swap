/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:48:28 by mabois            #+#    #+#             */
/*   Updated: 2020/04/24 10:48:30 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_read_buffer_norme_1(t_piles *piles, char *bf, int *buffer_len)
{
	if (bf[0] == 's' && bf[1] == 'a' && ft_shift(bf, buffer_len, 3))
		ft_operation_swap_sa(piles);
	else if (bf[0] == 's' && bf[1] == 'b' && ft_shift(bf, buffer_len, 3))
		ft_operation_swap_sb(piles);
	else if (bf[0] == 's' && bf[1] == 's' && ft_shift(bf, buffer_len, 3))
		ft_operation_swap_ss(piles);
	else if (bf[0] == 'p' && bf[1] == 'a' && ft_shift(bf, buffer_len, 3))
		ft_operation_push_pa(piles);
	else if (bf[0] == 'p' && bf[1] == 'b' && ft_shift(bf, buffer_len, 3))
		ft_operation_push_pb(piles);
	else if (bf[0] == 'r' && bf[1] == 'a' && ft_shift(bf, buffer_len, 3))
		ft_operation_rotate_ra(piles);
	else if (bf[0] == 'r' && bf[1] == 'b' && ft_shift(bf, buffer_len, 3))
		ft_operation_rotate_rb(piles);
	else if (bf[0] == 'r' && bf[1] == 'r' && ft_shift(bf, buffer_len, 3))
		ft_operation_rotate_rr(piles);
	else
		ft_exit(piles);
}

void	ft_read_buffer_norme_2(t_piles *piles, char *buffer, int *buffer_len)
{
	if (buffer[2] == 'a' && ft_shift(buffer, buffer_len, 4))
		ft_operation_revers_rra(piles);
	else if (buffer[2] == 'b' && ft_shift(buffer, buffer_len, 4))
		ft_operation_revers_rrb(piles);
	else if (buffer[2] == 'r' && ft_shift(buffer, buffer_len, 4))
		ft_operation_revers_rrr(piles);
	else
		ft_exit(piles);
}

void	ft_read_buffer(t_piles *piles, char *buffer, int *buffer_len)
{
	while (*buffer_len > 2)
		if (buffer[2] == '\n')
			ft_read_buffer_norme_1(piles, buffer, buffer_len);
		else if (*buffer_len > 3 && buffer[0] == 'r' &&
				buffer[1] == 'r' && buffer[3] == '\n')
			ft_read_buffer_norme_2(piles, buffer, buffer_len);
		else
			ft_exit(piles);
	if ((*buffer_len > 0 && buffer[0] == '\n') ||
			(*buffer_len > 1 && (buffer[0] == '\n' || buffer[1] == '\n')))
		ft_exit(piles);
}

int		main(int argc, char **argv)
{
	t_piles	piles;
	char	reader[128];
	int		reader_len;
	char	buffer[256];
	int		buffer_len;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	ft_init(&piles);
	piles.silence_mod = TRUE;
	ft_input_args(argc, argv, &piles, 0);
	ft_check_argv_input(&piles);
	buffer_len = 0;
	ft_clear_buffer(reader, 128);
	ft_clear_buffer(buffer, 256);
	while ((reader_len = read(0, reader, 128 - 1)) > 0)
	{
		ft_add_reader_to_buffer(reader, buffer, reader_len, &buffer_len);
		ft_clear_buffer(reader, reader_len);
		ft_read_buffer(&piles, buffer, &buffer_len);
	}
	ft_putstr_fd(STDOUT_FILENO,
			ft_is_sorted_down(&piles, PILE_A, TRUE) ? "OK\n" : "KO\n");
	ft_free_piles(&piles);
	return (EXIT_SUCCESS);
}
