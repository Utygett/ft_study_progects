NAME     =	containers

SOURSE   =  main.cpp

OBJ      =	$(SOURSE:%.cpp=%.o)

DEP      =	$(SOURSE:%.cpp=%.d)

CPPFLAGS =	-MMD -std=c++98 -g -Wall -Wextra -Werror -fsanitize=address

all      :	$(NAME)

$(NAME)  :	$(OBJ) 
			c++ $(CPPFLAGS) $(OBJ) -o $@

%.o 	 :	%.c
			c++ $(CPPFLAGS) -c $< -o $@

-include $(DEP)

clean	 : 
			rm -f $(OBJ) $(DEP)
		
fclean	 :	clean
			rm -f $(NAME)


re		 :	fclean all

.PHONY 	 :	all clean fclean re 
