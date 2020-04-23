#include "push_swap.h"

void	ft_clear(char *str, int size)
{
	int i;

	i = -1;
	while (++i < size)
	{
		str[i] = 0;
	}
}

void	ft_add_reader_to_buffer(char *reader, char *buffer, int reader_len, int *buffer_len)
{
	int i;

	i = -1;
	while (++i < reader_len)
	{
		buffer[*buffer_len + i] = reader[i];
	}
	*buffer_len = *buffer_len + reader_len;
}

void	ft_buffer_shift(char *buffer, int *buffer_len, int shift)
{
	int i;

	i = -1;
	while (++i < *buffer_len - shift)
	{
		buffer[i] = buffer[i + shift];
	}
	while (++i < *buffer_len)
	{
		buffer[i] = 0;
	}
	*buffer_len = *buffer_len - shift;
}

void	ft_read_buffer(t_piles *piles, char *buffer, int *buffer_len)
{
	while (*buffer_len > 2)
	{
		if (buffer[2] == '\n')
		{
			if (buffer[0] == 's' && buffer[1] == 'a')
			{
				ft_buffer_shift(buffer, buffer_len, 3);
				ft_operation_swap_sa(piles);
			}
			else if (buffer[0] == 's' && buffer[1] == 'b')
			{
				ft_buffer_shift(buffer, buffer_len, 3);
				ft_operation_swap_sb(piles);
			}
			else if (buffer[0] == 's' && buffer[1] == 's')
			{
				ft_buffer_shift(buffer, buffer_len, 3);
				ft_operation_swap_ss(piles);
			}
			else if (buffer[0] == 'p' && buffer[1] == 'a')
			{
				ft_buffer_shift(buffer, buffer_len, 3);
				ft_operation_push_pa(piles);
			}
			else if (buffer[0] == 'p' && buffer[1] == 'b')
			{
				ft_buffer_shift(buffer, buffer_len, 3);
				ft_operation_push_pb(piles);
			}
			else if (buffer[0] == 'r' && buffer[1] == 'a')
			{
				ft_buffer_shift(buffer, buffer_len, 3);
				ft_operation_rotate_ra(piles);
			}
			else if (buffer[0] == 'r' && buffer[1] == 'b')
			{
				ft_buffer_shift(buffer, buffer_len, 3);
				ft_operation_rotate_rb(piles);
			}
			else if (buffer[0] == 'r' && buffer[1] == 'r')
			{
				ft_buffer_shift(buffer, buffer_len, 3);
				ft_operation_rotate_rr(piles);
			}
			else {
				ft_exit(piles);
			}
		}
		else if (*buffer_len > 3 && buffer[0] == 'r' && buffer[1] == 'r' && buffer[3] == '\n')
		{
			if (buffer[2] == 'a')
			{
				ft_buffer_shift(buffer, buffer_len, 4);
				ft_operation_revers_rra(piles);
			}
			else if (buffer[2] == 'b')
			{
				ft_buffer_shift(buffer, buffer_len, 4);
				ft_operation_revers_rrb(piles);
			}
			else if (buffer[2] == 'r')
			{
				ft_buffer_shift(buffer, buffer_len, 4);
				ft_operation_revers_rrr(piles);
			}
			else {
				ft_exit(piles);
			}
		}
		else {
			ft_exit(piles);		
		}
	}
	if ((*buffer_len > 0 && buffer[0] == '\n') || (*buffer_len > 1 && (buffer[0] == '\n' || buffer[1] == '\n')))
		ft_exit(piles);		
}

int main(int argc, char **argv)
{
	t_piles	piles;
	
	char 	reader[128];
	int		reader_len;
	char 	buffer[256];
	int		buffer_len;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	ft_init(&piles);
	piles.silence_mod = TRUE;
	ft_input_args(argc, argv, &piles, 0);
	ft_check_argv_input(&piles);

	buffer_len = 0;
	ft_clear(reader, 128);
	ft_clear(buffer, 256);

	while ((reader_len = read(0, reader, 128 - 1)) > 0)
	{
		ft_add_reader_to_buffer(reader, buffer, reader_len, &buffer_len);

		ft_clear(reader, reader_len);
		ft_read_buffer(&piles, buffer, &buffer_len);
	}

	if (ft_is_sorted_down(&piles, PILE_A, TRUE))
		ft_putstr_fd(STDOUT_FILENO, "OK\n");
	else
		ft_putstr_fd(STDOUT_FILENO, "KO\n");

	ft_free_piles(&piles);
	return (EXIT_SUCCESS);
}