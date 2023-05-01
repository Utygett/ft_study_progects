# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 11:40:33 by utygett           #+#    #+#              #
#    Updated: 2021/11/25 10:40:56 by utygett          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOCOLOR	=	'\033[0m'

RED		=	'\033[0;31m'

GREEN	=	'\033[0;32m'

NAME	=	philo

SRC		=	main.c utils.c treads_and_mutex.c time_utils.c 

OBJ_M	=	$(SRC:%.c=%.o)

DEP		=	$(SRC:%.c=%.d)

CFLAGS	=	-MD -Wall -Werror -Wextra

CC		=	gcc

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ_M)
			@$(CC) $(CFLAGS) $(OBJ_M) -o $(NAME)
			@printf $(GREEN)"Created $(NAME)\n"$(NOCOLOR)
	
%.o		:	%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean	:
			@$(RM) $(OBJ_M) $(DEP) 
			@printf $(RED)"Temporary files have been deleted!\n"$(NOCOLOR)
fclean	:	clean
			@$(RM) $(NAME)
			@printf $(RED)"Binary files have been deleted!\n"$(NOCOLOR)
	
re		:	fclean all

-include $(DEP) 

.PHONY	:	all clean fclean re 