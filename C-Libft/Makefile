# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 11:40:33 by utygett           #+#    #+#              #
#    Updated: 2021/10/13 18:44:44 by utygett          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRC		=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c	\
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c	\
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c

SRCS_B	=	ft_lstnew_bonus.c	\
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstmap_bonus.c
			
OBJ_M	=	$(SRC:%.c=%.o)

DEP_M	=	$(SRC:%.c=%.d)

OBJ_B	=	$(SRCS_B:%.c=%.o)

DEP_B	=	$(SRCS_B:%.c=%.d)

ifdef MAKE_BONUS
	OBJ = $(OBJ_B) $(OBJ_M)
else
	OBJ = $(OBJ_M)
endif

CFLAGS	=	-MD -Wall -Werror -Wextra

CC		=	gcc

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rcs $(NAME) $?

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@
	
clean	:
			$(RM) $(OBJ_M) $(OBJ_B) $(DEP_M) $(DEP_B)

fclean	:	clean
			$(RM) $(NAME)
	
re		:	fclean all

bonus	:
			@make MAKE_BONUS=0 all

-include $(DEP_M) $(DEP_B)

.PHONY	:	all clean fclean re bonus