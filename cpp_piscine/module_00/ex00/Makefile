NAME     =	megaphone 

SOURSE   =	megaphone.cpp

OBJ      =	$(SOURSE:%.cpp=%.o)

CPPFLAGS =	-Wall -Wextra -Werror -std=c++98
all      :	$(NAME)

$(NAME)  :	$(OBJ)
			clang++ $(CPPFLAGS) $(OBJ) -o $@

%.o 	 :	%.c
			clang++ $(CPPFLAGS) -c $< -o $@



clean	 : 
			rm -f $(OBJ)
		
fclean	 :	clean
			rm -f $(NAME)


re		 :	fclean all

.PHONY 	 :	all clean fclean re 
