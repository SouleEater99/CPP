CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g -Wno-shadow
NAME = FragTrap
SRC =   ./main.cpp\
		./ClapTrap.cpp\
		./FragTrap.cpp
		./ScavTrap.cpp
		./DiamondTrap.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)