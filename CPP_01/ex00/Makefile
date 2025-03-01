CXX =c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME = zombie
SRC =   ./main.cpp\
		./newZombie.cpp\
		./randomChump.cpp\
		./Zombie.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all