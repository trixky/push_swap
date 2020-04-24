/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabois <mabois@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:51:29 by mabois            #+#    #+#             */
/*   Updated: 2020/04/24 10:51:31 by mabois           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>

# define INT_MAX				2147483647
# define INT_MIN				-2147483648

# define BUFFER_FILE_SIZE		20000

# define ERROR					-1
# define FALSE					0
# define TRUE					1

# define POSITIF				1
# define NEGATIF				-1

# define PILE_A					0
# define PILE_B					1

# define SEED_GENERATOR 		33333
# define RAND_MODULO			600
# define BRUT_FORCE_ARRAY_SIZE	12

# define OPTION_V				1
# define OPTION_C				10
# define OPTION_H				100
# define OPTION_N				1000
# define OPTION_F				10000

# define NOTHING				0
# define SA						1
# define RA						2
# define RRA					3
# define START_VALUE			12

# define INSTRUCTION_NBR		3

# define KNRM					"\x1B[0m"
# define KRED					"\x1B[31m"
# define KGRN					"\x1B[32m"
# define KYEL					"\x1B[33m"
# define KBLU					"\x1B[34m"
# define KMAG					"\x1B[35m"
# define KCYN					"\x1B[36m"
# define KWHT					"\x1B[37m"

typedef struct	s_piles
{
	int			time;
	int			options;
	int			silence_mod;
	int			capacity;
	int			*a;
	int			*b;
	int			*a_temp;
	int			*b_temp;
	int			a_len;
	int			b_len;
	int			a_len_temp;
	int			b_len_temp;
	int			nbr_operation;
	int			nbr_operation_temp;
	int			brute_force_array[BRUT_FORCE_ARRAY_SIZE];
	int			brute_force_array_save[BRUT_FORCE_ARRAY_SIZE];
}				t_piles;

void			ft_start_test(t_piles *piles, const int silence_mod);
int				ft_stop_test(t_piles *piles, const int silence_mod);
int				ft_first_is_the_smallest(t_piles *piles, const int pile);
int				ft_first_is_the_greatest(t_piles *piles, const int pile);
void			ft_operation_push_pa(t_piles *piles);
void			ft_operation_push_pb(t_piles *piles);
void			ft_operation_revers_rra(t_piles *piles);
void			ft_operation_revers_rrb(t_piles *piles);
void			ft_operation_revers_rrr(t_piles *piles);
void			ft_operation_rotate_ra(t_piles *piles);
void			ft_operation_rotate_rb(t_piles *piles);
void			ft_operation_rotate_rr(t_piles *piles);
void			ft_operation_swap_sa(t_piles *piles);
void			ft_operation_swap_sb(t_piles *piles);
void			ft_operation_swap_ss(t_piles *piles);
void			ft_init(t_piles *piles);
void			ft_check_argv_input(t_piles *piles);
void			ft_clear_buffer(char *str, int size);
void			ft_add_reader_to_buffer(char *reader, char *buffer,
				int reader_len, int *buffer_len);
int				ft_shift(char *buffer, int *buffer_len, int shift);
void			ft_insertion_sort(t_piles *piles);
void			ft_brute_force_sort(t_piles *piles);
void			ft_brute_force_show(t_piles *piles);
int				ft_brute_force_array_size(t_piles *piles);
int				ft_brute_force_array_size_save(t_piles *piles);
void			ft_brute_force_save(t_piles *piles);
int				ft_first_is_the_smallest(t_piles *piles, const int pile);
int				ft_first_is_the_greatest(t_piles *piles, const int pile);
int				ft_is_sorted_down(t_piles *piles,
				const int pile, const int silence_mod);
int				ft_is_sorted_up(t_piles *piles, const int pile,
				const int silence_mod);
void			ft_operation_revers_rra_x_time(t_piles *piles, const int time);
void			ft_operation_revers_rrb_x_time(t_piles *piles, const int time);
void			ft_operation_rotate_rr_x_time(t_piles *piles, const int time);
void			ft_operation_revers_rrr_x_time(t_piles *piles, const int time);
int				ft_find_smallest_index(t_piles *piles, const int pile);
int				ft_find_greatest_index(t_piles *piles, const int pile);
int				ft_find_below_b(int nbr, t_piles *piles);
int				ft_find_above_a(int nbr, t_piles *piles);
void			ft_rotate_sort_pile(t_piles *piles, const int pile);
void			ft_smart_push_pb_ra(int index, t_piles *piles);
void			ft_best_move_norme_1(t_piles *piles, int *all);
void			ft_best_move_norme_2(t_piles *piles, int *all);
int				ft_best_move(t_piles *piles);
void			ft_smart_push_pb_rra(int index, t_piles *piles);
int				ft_find_smallest_value(t_piles *piles, const int pile);
int				ft_find_greatest_value(t_piles *piles, const int pile);
void			ft_operation_rotate_ra_x_time(t_piles *piles, const int time);
void			ft_operation_rotate_rb_x_time(t_piles *piles, const int time);
int				ft_strlen(char *str);
int				ft_putstr_fd(int fd, char *str);
int				ft_putchar_fd(int fd, char c);
void			ft_check_minus_alone(t_piles *piles, char *str);
int				ft_str_to_int(t_piles *piles, char *str);
void			*ft_free(void *ptr);
void			ft_swap_int(int *a, int *b);
void			ft_putnbr(int nb);
void			ft_exit(t_piles *piles);
void			ft_free_piles(t_piles *piles);
void			ft_input_args(int argc, char **argv,
				t_piles *piles, int options_number);
void			ft_input_args_file(int file_name, t_piles *piles, char **argv);
int				ft_have_option(int option, t_piles *piles);
void			ft_vn_activate(t_piles *piles);
int				ft_check_double_option(int option, int options, t_piles *piles);
int				ft_check_option(int argc, char **argv,
				int *file_name, t_piles *piles);
int				ft_options_number(int options);
void			ft_show_piles(t_piles *piles);

#endif
