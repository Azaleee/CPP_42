SRC = *.cpp
NAME = mutant
CC = c++ -Wall -Wextra -Werror -std=c++98 -g3

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all