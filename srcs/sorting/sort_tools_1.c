#include "push_swap.h"

int		ft_first_is_the_smallest(t_piles *piles, const int pile)
{
	int i;
	int	first;

	i = -1;
	first = (pile == PILE_A ? piles->a[0] : piles->b[0]);
	while (++i < (pile == PILE_A ? piles->a_len : piles->b_len))
		if ((pile == PILE_A ? piles->a[i] : piles->b[i]) < first)
			return (FALSE);
	return (TRUE);
}

int		ft_first_is_the_greatest(t_piles *piles, const int pile)
{
	int i;
	int	first;

	i = -1;
	first = (pile == PILE_A ? piles->a[0] : piles->b[0]);
	while (++i < (pile == PILE_A ? piles->a_len : piles->b_len))
		if ((pile == PILE_A ? piles->a[i] : piles->b[i]) > first)
			return (FALSE);
	return (TRUE);
}

int		ft_is_sorted_down(t_piles *piles,
		const int pile, const int silence_mod)
{
	int	i;

	i = -1;
	while (++i + 1 < (pile == PILE_A ? piles->a_len : piles->b_len))
		if ((pile == PILE_A ? piles->a[i] : piles->b[i]) >
				(pile == PILE_A ? piles->a[i + 1] : piles->b[i + 1]))
		{
			if (silence_mod == FALSE)
				printf("pile %c n'est pas trille en down\n",
				(pile == PILE_A ? 'a' : 'b'));
			return (FALSE);
		}
	if (silence_mod == FALSE)
		printf("pile %c est trille en down\n", (pile == PILE_A ? 'a' : 'b'));
	return (TRUE);
}

int		ft_is_sorted_up(t_piles *piles,
		const int pile, const int silence_mod)
{
	int	i;

	i = -1;
	while (++i + 1 < (pile == PILE_A ? piles->a_len : piles->b_len))
		if ((pile == PILE_A ? piles->a[i] : piles->b[i]) <
				(pile == PILE_A ? piles->a[i + 1] : piles->b[i + 1]))
		{
			if (silence_mod == FALSE)
				printf("pile %c n'est pas trille en up\n",
				(pile == PILE_A ? 'a' : 'b'));
			return (FALSE);
		}
	if (silence_mod == FALSE)
		printf("pile %c est trille en up\n", (pile == PILE_A ? 'a' : 'b'));
	return (TRUE);
}
