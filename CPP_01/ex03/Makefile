CXX =c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Human
SRC =   ./main.cpp\
		./Weapon.cpp\
		./HumanA.cpp\
		./HumanB.cpp


OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: CFLAGS += -g -fsanitize=address

debug: re

run: $(NAME)
	./$(NAME)