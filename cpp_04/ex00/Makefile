CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
NAME = animal
SRC =   ./main.cpp\
		./Animal.cpp\
		./Cat.cpp\
		./Dog.cpp\
		./WrongAnimal.cpp\
		./WrongCat.cpp\

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

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