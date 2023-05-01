# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 11:40:33 by utygett           #+#    #+#              #
#    Updated: 2021/11/14 16:18:06 by utygett          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOCOLOR	=	'\033[0m'

RED		=	'\033[0;31m'

GREEN	=	'\033[0;32m'

NAME	=	push_swap

NAME_B	=	checker

SRC		=	push_swap.c push_swap_utils.c push_swap_operations_one.c push_swap_operations_two.c push_swap_sorting_low.c push_swap_check_rotate.c push_swap_sorting_one.c

SRC_B	=	push_swap_bonus.c push_swap_operations_one_bonus.c push_swap_utils_bonus.c
			
OBJ_M	=	$(SRC:%.c=%.o)

OBJ_B	=	$(SRC_B:%.c=%.o)

DEP		=	$(SRC:%.c=%.d)

DEP_B	=	$(SRC_B:%.c=%.d)

CFLAGS	=	-MD -Wall -Werror -Wextra

CC		=	gcc

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ_M)
			@$(CC) $(CFLAGS) $(OBJ_M) -o $(NAME)
			@printf $(GREEN)"Created $(NAME)\n"$(NOCOLOR)
	
%.o		:	%.c
			@$(CC) $(CFLAGS) -c $< -o $@

bonus   :	
			@make OBJ_M="$(OBJ_B)" NAME="$(NAME_B)" all

clean	:
			@$(RM) $(OBJ_M) $(OBJ_B) $(DEP) $(DEP_B)
			@printf $(RED)"Temporary files have been deleted!\n"$(NOCOLOR)
fclean	:	clean
			@$(RM) $(NAME) $(NAME_B)
			@printf $(RED)"Binary files have been deleted!\n"$(NOCOLOR)
	
re		:	fclean all

-include $(DEP) $(DEP_B)

.PHONY	:	all clean fclean re bonus