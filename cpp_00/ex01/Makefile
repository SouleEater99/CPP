CC = c++
CFLAGS = -Wall -Wextra -Werror
NAME = phonebook
SRC =   ./PhoneBook.cpp\
		./main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I./ -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
