CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
SRC =   ./PhoneBook.cpp\
		./Contact.cpp\
		./main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -I./ -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
