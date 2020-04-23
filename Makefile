NAME_CHECKER = checker

NAME_PUSH_SWAP = push_swap

NAME_GENERATOR = generator

INCLUDE = -Iincludes

CHECKER_SRCS = srcs/prog/main_checker.c

PUSH_SWAP_SRCS = srcs/prog/main_push_swap.c

GENERATOR_SRCS = srcs/generator/main_generator.c

COMMON_SRCS =	srcs/cost_calculator/cost_calculator.c\
				srcs/operation/operation_push.c\
				srcs/operation/operation_revers.c\
				srcs/operation/operation_rotate.c\
				srcs/operation/operation_swap.c\
				srcs/prog/checker.c\
				srcs/prog/init.c\
				srcs/sorting/brute_force_sort.c\
				srcs/sorting/insertion_sort.c\
				srcs/sorting/sort_tools_1.c\
				srcs/sorting/sort_tools_2.c\
				srcs/sorting/sort_tools_3.c\
				srcs/utils/utils_1.c\
				srcs/utils/utils_2.c\
				srcs/utils/utils_exit.c\
				srcs/utils/utils_input.c\
				srcs/utils/utils_options.c\
				srcs/utils/utils_show.c

CHECKER_OBJ = $(COMMON_SRCS:.c=.o) $(CHECKER_SRCS:.c=.o)
PUSH_SWAP_OBJ = $(COMMON_SRCS:.c=.o) $(PUSH_SWAP_SRCS:.c=.o)
GENERATOR_OBJ = $(COMMON_SRCS:.c=.o) $(GENERATOR_SRCS:.c=.o)

FLAGS= -Wall -Wextra -Werror -fsanitize=address -g3

GCC = gcc

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP) $(NAME_GENERATOR)

%.o:%.c
	${CC} ${FLAGS} ${INCLUDE} -c $< -o $@

$(NAME_CHECKER): $(CHECKER_OBJ)
	${CC} ${FLAGS} ${INCLUDE} ${CHECKER_OBJ} -o $@
	
$(NAME_PUSH_SWAP): $(PUSH_SWAP_OBJ)
	${CC} ${FLAGS} ${INCLUDE} ${PUSH_SWAP_OBJ} -o $@

$(NAME_GENERATOR): $(GENERATOR_OBJ)
	${CC} ${FLAGS} ${INCLUDE} ${GENERATOR_OBJ} -o $@

clean:
	rm -rf $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)

fclean: clean
	rm -rf ${NAME_CHECKER} ${NAME_PUSH_SWAP} ${NAME_GENERATOR}

re: fclean all

.PHONY: re, clean, fclean, all, bonus