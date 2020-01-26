#include "push_swap.h"

int main(int argc, char **argv)
{
	t_piles	piles;
	
	ft_init(&piles);
	ft_input_args(argc, argv, &piles);
	ft_check_argv_input(&piles);	
	printf("===================== start ...\n");
	ft_show_piles(&piles);
		
	printf("===================== swap sa ...\n");
	ft_operation_swap_sa(&piles);
	ft_show_piles(&piles);
	
	printf("===================== push pb pb pb ...\n");
	ft_operation_push_pb(&piles);
	ft_operation_push_pb(&piles);
	ft_operation_push_pb(&piles);
	ft_show_piles(&piles);
	
	printf("===================== push rr rr rr ...\n");
	ft_operation_rotate_rr(&piles);
	ft_show_piles(&piles);
	
	printf("===================== push rrr rrr rrr ...\n");
	ft_operation_revers_rrr(&piles);
	ft_show_piles(&piles);
	
	printf("===================== swap sa ...\n");
	ft_operation_swap_sa(&piles);
	ft_show_piles(&piles);
	
	printf("===================== swap pa pa ...\n");
	ft_operation_push_pa(&piles);
	ft_operation_push_pa(&piles);
	ft_operation_push_pa(&piles);
	ft_show_piles(&piles);
	
	ft_free_piles(&piles);
	return (EXIT_SUCCESS);
}