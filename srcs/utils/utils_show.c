#include "push_swap.h"

void	ft_show_piles(t_piles *piles)
{
	int i;
	
	i = -1;
	ft_putstr_fd(STDIN_FILENO, "=================\tbegin\n");
	ft_putstr_fd(STDIN_FILENO, "    A\t    B\n");
	while (++i < piles->capacity)
	{
		if (i < piles->a_len)
			ft_putnbr(piles->a[i]);
		else
			ft_putchar_fd(STDOUT_FILENO, '.');
		ft_putchar_fd(STDOUT_FILENO, '\t');
		if (i < piles->b_len)
			ft_putnbr(piles->b[i]);
		else
			ft_putchar_fd(STDOUT_FILENO, '.');
		ft_putchar_fd(STDOUT_FILENO, '\n');
	}
	ft_putstr_fd(STDIN_FILENO, "=================\tend\n");
}