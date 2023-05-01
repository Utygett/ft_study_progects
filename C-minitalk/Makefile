# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 11:40:33 by utygett           #+#    #+#              #
#    Updated: 2021/11/16 16:14:25 by utygett          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOCOLOR	=	'\033[0m'

RED		=	'\033[0;31m'

GREEN	=	'\033[0;32m'

NAME_S	=	server

NAME_C	=	client

SRC_S	=	server.c server_utils.c

SRC_C	=	client.c

SRC_S_B	=	server_bonus.c server_utils_bonus.c

SRC_C_B	=	client_bonus.c

OBJ_S_B	=	$(SRC_S_B:%.c=%.o)

OBJ_C_B	=	$(SRC_C_B:%.c=%.o)

OBJ_S	=	$(SRC_S:%.c=%.o)

OBJ_C	=	$(SRC_C:%.c=%.o)

DEP_S_B	=	$(SRC_S_B:%.c=%.d)

DEP_C_B	=	$(SRC_C_B:%.c=%.d)

DEP_S	=	$(SRC_S:%.c=%.d)

DEP_C	=	$(SRC_C:%.c=%.d)

CFLAGS	=	-MD -Wall -Wextra -Werror -fsanitize=address

CC		=	gcc

RM		=	rm -f

all		:	$(NAME_S) $(NAME_C)

$(NAME_S)	:	$(OBJ_S)
			@$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S)
			@printf $(GREEN)"Created $(NAME_S)\n"$(NOCOLOR)

$(NAME_C)	:	$(OBJ_C)
			@$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)
			@printf $(GREEN)"Created $(NAME_C)\n"$(NOCOLOR)

%.o		:	%.c
			@$(CC) $(CFLAGS) -c $< -o $@


bonus   :	
			@make OBJ_S="$(OBJ_S_B)" OBJ_C="$(OBJ_C_B)" all

clean	:
			@$(RM) $(OBJ_S) $(OBJ_C) $(DEP_S) $(DEP_C) $(OBJ_S_B) $(OBJ_C_B) $(DEP_S_B) $(DEP_C_B)
			@printf $(RED)"Temporary files have been deleted!\n"$(NOCOLOR)
fclean	:	clean
			@$(RM) $(NAME_S) $(NAME_C)
			@printf $(RED)"Binary files have been deleted!\n"$(NOCOLOR)
	
re		:	fclean all

-include $(DEP_S) $(DEP_C) $(DEP_S_B) $(DEP_C_B)

.PHONY	:	all clean fclean re bonus