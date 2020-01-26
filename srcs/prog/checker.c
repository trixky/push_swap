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
				ft_exit(piles, "ft_check_argv_input() : duplicate numbers are present\n");
	}
}