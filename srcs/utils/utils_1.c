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

void	ft_check_minus_alone(t_piles *piles, char *str)
{
	if (ft_strlen(str) == 1 && str[0] == '-')
		ft_exit(piles);
}

int		ft_str_to_int(t_piles *piles, char *str)
{
	int				i;
	long long int	sign;
	long long int	number;

	ft_check_minus_alone(piles, str);
	i = 0;
	sign = POSITIF;
	number = 0;
	if (*str)
	{
		if (*str == '-' && ++i > -1)
			sign = NEGATIF;
		while (str[i] >= '0' && str[i] <= '9')
		{
			number *= 10;
			number += sign * (str[i++] - 48);
			if (number > INT_MAX || number < INT_MIN)
				ft_exit(piles);
		}
		if (str[i] != '\0' && str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
			ft_exit(piles);
	}
	else
		ft_exit(piles);
	return (number);
}
