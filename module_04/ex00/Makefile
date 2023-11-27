NAME = Animal
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJECT = $(SOURCES:.cpp=.o)
SOURCES = main.cpp Animal.cpp Cat.cpp Dog.cpp

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all