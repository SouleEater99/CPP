CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
NAME = Human
SRC =   ./main.cpp\
		./Weapon.cpp\
		./HumanA.cpp\
		./HumanB.cpp


OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all