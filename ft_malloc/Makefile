# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 11:40:33 by utygett           #+#    #+#              #
#    Updated: 2022/04/03 18:35:18 by utygett          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		malloc

SRC			=		malloc.c

FTDIR		= 		./libft/

LIBFT		= 		libft.a
		
OBJ_M		=		$(SRC:%.c=%.o)

DEP			=		$(SRC:%.c=%.d)

CFLAGS		=		-MD -g -Werror -Wall -Wextra 
# -fsanitize=address 

CC		=	gcc

RM		=	rm -f

all		:	libmake $(NAME)

$(NAME)	:	$(OBJ_M) $(FTDIR)$(LIBFT)
			$(CC) $(CFLAGS) $(OBJ_M) $(FTDIR)$(LIBFT) -o $(NAME)

bonus	:	all

libmake	:	
			@make -C $(FTDIR)
 
%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			@make clean -C $(FTDIR)
			$(RM) $(OBJ_M) $(DEP)

fclean	:	clean
			@make fclean -C $(FTDIR)
			$(RM) $(NAME)
	
re		:	fclean all

-include $(DEP)

.PHONY	:	all clean fclean re bonus