CC = c++
CFLAGS = -Wall -Wextra -Werror
NAME = phonebook
SRC =   ./PhoneBook.cpp
HEADER = ./PhoneBook.hpp \
		./Contact.hpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
