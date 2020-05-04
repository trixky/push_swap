#include "push_swap.h"

void	ft_clear_buffer(char *str, int size)
{
	int i;

	i = -1;
	while (++i < size)
	{
		str[i] = 0;
	}
}

void	ft_add_reader_to_buffer(char *reader, char *buffer,
		int reader_len, int *buffer_len)
{
	int i;

	i = -1;
	while (++i < reader_len)
	{
		buffer[*buffer_len + i] = reader[i];
	}
	*buffer_len = *buffer_len + reader_len;
}

int		ft_shift(char *buffer, int *buffer_len, int shift)
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
	return (TRUE);
}
