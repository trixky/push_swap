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

int		ft_input_args_insert_number(int argc, char **argv, t_piles *piles, int insert_mod)
{
	int	i;
	int j;
	int k;
	
	i = 0;
	k = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i + 1][j])
		{
			if (insert_mod)
				piles->a[k] = ft_str_to_int(piles, argv[i + 1] + j);
			j += ft_next_number_in_str(argv[i + 1] + j);
			k++;
		}
		i++;
	}
	return (k);
}

void	ft_input_args(int argc, char **argv, t_piles *piles)
{
	piles->capacity = ft_input_args_insert_number(argc, argv, piles, FALSE);
	if ((piles->a = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles, "malloc() : return NULL...");
	if ((piles->b = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles, "malloc() : return NULL...");
	if ((piles->a_temp = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles, "malloc() : return NULL...");
	if ((piles->b_temp = malloc(sizeof(int) * piles->capacity)) == NULL)
		ft_exit(piles, "malloc() : return NULL...");
	piles->a_len = piles->capacity;
	piles->b_len = 0;
	ft_input_args_insert_number(argc, argv, piles, TRUE);
}
