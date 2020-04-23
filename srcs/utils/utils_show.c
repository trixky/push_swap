#include "push_swap.h"

void	ft_show_piles(t_piles *piles)
{
	int i;
	
	i = -1;
	if (ft_have_option(OPTION_C, piles))
		write(1, KGRN, ft_strlen(KGRN));
	ft_putstr_fd(STDOUT_FILENO, "=================\tbegin\n");
	if (ft_have_option(OPTION_C, piles))
	write(1, KNRM, ft_strlen(KNRM));
	ft_putstr_fd(STDOUT_FILENO, "    A\t    B\n");
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
	if (ft_have_option(OPTION_C, piles))
	write(1, KYEL, ft_strlen(KYEL));
	ft_putstr_fd(STDOUT_FILENO, "=================\tend\n");
	if (ft_have_option(OPTION_C, piles))
	write(1, KNRM, ft_strlen(KNRM));
}