#include "push_swap.h"

int ft_is_already_taken(int *array, int len, int nbr)
{
	int i;
	
	i = -1;
	while (++i < len)
		if (array[i] == nbr)
			return (TRUE);
	return (FALSE);
}

int main(int argc, char **argv)
{
	int i;
	int rdm;
	int len;
	int *number_used;

	srand(time(NULL));
	rdm = rand() % SEED_GENERATOR;
	if (argc != 2)
		ft_exit(NULL, "generator : please enter one arg...\n");
	len = ft_str_to_int(NULL, argv[1]);
	if ((number_used = malloc(sizeof(int) * len)) == NULL)
		ft_exit(NULL, "generator : malloc return NULL...\n");
	i = -1;
	while (++i < len)
	{
		while (ft_is_already_taken(number_used, len, rdm % RAND_MODULO))
			rdm += ((((7 * 8 * rdm) / 2) + 9) * 789 + 333) * (rand() % SEED_GENERATOR);
		number_used[i] = rdm % RAND_MODULO;
	}
	i = -1;
	while (++i < len)
	{
		if (i != 0)
			ft_putchar_fd(STDOUT_FILENO, ' ');
		ft_putnbr(number_used[i]);
	}
	free(number_used);
	return (EXIT_SUCCESS);
}