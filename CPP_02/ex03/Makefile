CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
NAME = bsp
SRC =   ./main.cpp\
		./Fixed.cpp\
		./Point.cpp

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