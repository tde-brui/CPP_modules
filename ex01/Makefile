NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror
SRC = phonebook.cpp main.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ);

fclean: clean
	rm -rf $(NAME);

re: fclean all