NAME     =	bank

SOURSE   =	tests.cpp Account.cpp 

OBJ      =	$(SOURSE:%.cpp=%.o)

DEP      =	$(SOURSE:%.cpp=%.d)

CPPFLAGS =	-MMD -Wall -Wextra -Werror -std=c++98 -g
all      :	$(NAME)

$(NAME)  :	$(OBJ)
			clang++ $(CPPFLAGS) $(OBJ) -o $@

%.o 	 :	%.c
			clang++ $(CPPFLAGS) -c $< -o $@

-include $(DEP)

clean	 : 
			rm -f $(OBJ) $(DEP)
		
fclean	 :	clean
			rm -f $(NAME)


re		 :	fclean all

.PHONY 	 :	all clean fclean re 
