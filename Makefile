CC = gcc -Wall -Werror -Wextra -g

NAME = push_swap

SRC = push_swap.c \
		./src/external_func/ft_atol.c \
		./src/external_func/ft_lstadd_back.c \
		./src/external_func/ft_lstadd_front.c \
		./src/external_func/ft_lstlast.c \
		./src/external_func/ft_lstsize.c \
		./src/external_func/ft_lstnew.c\
		./src/external_func/ft_lstclear.c\
		./src/external_func/ft_strlen.c\
		./src/parsing_args/check_args.c\
		./src/authorized_op/revRotate_and_rrr.c\
		./src/authorized_op/rotate_and_rr.c\
		./src/authorized_op/swap_and_push.c\
		./src/basic_calc/calc_low_high.c\
		./src/basic_calc/calc_middle_med.c\
		./src/sorting/sort_above_five.c\
		./src/sorting/sort_four_five.c\
		./src/sorting/sort_four_five2.c\
		./src/sorting/sort_one_three.c\
		./src/sorting/helpers/check_moves.c \
		./src/sorting/helpers/check_update_pos.c \
		./src/sorting/helpers/cir_decir_dll.c \
		./src/sorting/helpers/cost_calc.c \
		./src/sorting/helpers/cost_calc2.c \
		./src/sorting/helpers/optimising.c \
		./src/sorting/helpers/optimising/loops_rr.c \
		./src/sorting/helpers/optimising/loops_rrr.c \
		./src/sorting/helpers/pushing_func.c \
		./src/sorting/helpers/pushing_func2.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean: clean
	 rm -f $(NAME)

re: fclean all

.PHONY : all clean bonus fclean re
