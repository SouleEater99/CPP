CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
NAME = AForm
SRC =   ./main.cpp\
		./Bureaucrat.cpp\
		./AForm.cpp\
		./ShrubberyCreationForm.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)