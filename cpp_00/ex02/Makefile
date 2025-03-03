CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Account
SRC =   ./Account.cpp\
		./tests.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -I./ -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
