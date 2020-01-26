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

void	ft_exit(t_piles *piles, char *str)
{
	ft_free_piles(piles);
	ft_putstr_fd(STDERR_FILENO, "ERROR: ");
	ft_putstr_fd(STDERR_FILENO, str);
	ft_putstr_fd(STDERR_FILENO, "\n");
	exit(EXIT_FAILURE);
}
