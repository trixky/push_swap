/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:44:33 by mabois            #+#    #+#             */
/*   Updated: 2020/04/24 10:44:34 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_next_number_in_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i++] == ' ')
			return (i);
	return (i);
}

int		ft_input_args_insert_number(int argc, char **argv,
		t_piles *piles, int *norme_array)
{
	int	i;
	int j;
	int k;

	i = norme_array[1];
	k = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i + 1][j])
		{
			if (norme_array[0])
				piles->a[k] = ft_str_to_int(piles, argv[i + 1] + j);
			j += ft_next_number_in_str(argv[i + 1] + j);
			k++;
		}
		i++;
	}
	return (k);
}

int		ft_input_args_insert_number_file(char *file_name,
		t_piles *piles, int insert_mod)
{
	int		i;
	int		k;
	int		fd;
	int		ret;
	char	buffer_file[BUFFER_FILE_SIZE + 1];

	i = 0;
	k = 0;
	if ((fd = open(file_name, O_RDONLY)) <= 0)
		ft_exit(piles);
	if ((ret = read(fd, buffer_file, BUFFER_FILE_SIZE)) >=
			BUFFER_FILE_SIZE)
		ft_exit(piles);
	while (i < ret)
	{
		if (insert_mod)
			piles->a[k] = ft_str_to_int(piles, buffer_file + i);
		i += ft_next_number_in_str(buffer_file + i);
		k++;
	}
	return (k);
}

void	ft_input_args(int argc, char **argv,
		t_piles *piles, int options_number)
{
	int norme_array[2];

	norme_array[0] = FALSE;
	norme_array[1] = options_number;
	piles->capacity = ft_input_args_insert_number(argc,
	argv, piles, norme_array);
	if ((piles->a = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles);
	if ((piles->b = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles);
	if ((piles->a_temp = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles);
	if ((piles->b_temp = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles);
	piles->a_len = piles->capacity;
	piles->b_len = 0;
	norme_array[0] = TRUE;
	ft_input_args_insert_number(argc, argv, piles, norme_array);
}

void	ft_input_args_file(int file_name, t_piles *piles, char **argv)
{
	piles->capacity = ft_input_args_insert_number_file(argv[file_name],
	piles, FALSE);
	if ((piles->a = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles);
	if ((piles->b = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles);
	if ((piles->a_temp = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles);
	if ((piles->b_temp = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles);
	piles->a_len = piles->capacity;
	piles->b_len = 0;
	ft_input_args_insert_number_file(argv[file_name], piles, TRUE);
}
