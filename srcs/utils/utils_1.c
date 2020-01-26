#include "push_swap.h"

int		ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_putchar_fd(int fd, char c)
{
	return (write(fd, &c, 1));
}

int		ft_putstr_fd(int fd, char *str)
{
	return (write(fd, str, ft_strlen(str)));
}

int		ft_str_to_int(t_piles *piles, char *str)
{
	int	i;
	int sign;
	int	number;
	
	i = 0;
	sign = POSITIF;
	number = 0;
	if (*str)
	{
		if (*str == '-')
		{
			sign = NEGATIF;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			number *= 10;
			number += sign * (str[i++] - 48);
		}
		if (str[i] != '\0' && str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
			ft_exit(piles, "ft_str_to_int() : str not a number...");
	}
	else
		ft_exit(piles, "ft_str_to_int() : str is empty...");
	return (number);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putstr_fd(STDOUT_FILENO, "-");
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar_fd(STDOUT_FILENO, nbr % 10 + 48);
}