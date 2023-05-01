# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 11:40:33 by utygett           #+#    #+#              #
#    Updated: 2021/10/21 14:34:13 by utygett          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	ft_printf.c ft_printf_utils.c 
			
			
			
OBJ_M	=	$(SRC:%.c=%.o)

DEP		=	$(SRC:%.c=%.d)

CFLAGS	=	-MD -Wall -Werror -Wextra

CC		=	gcc

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ_M)
			ar rcs $(NAME) $?
	
%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJ_M) $(DEP)

fclean	:	clean
			$(RM) $(NAME)
	
re		:	fclean all

-include $(DEP)

.PHONY	:	all clean fclean re 
