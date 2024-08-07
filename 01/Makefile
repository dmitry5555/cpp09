NAME = RPC

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

RM = @rm -f
END = \033[0;0m

SRC = $(shell find src -name '*.cpp')
OBJ = ${SRC:.cpp=.o}

all: $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			@echo "$(END)${NAME} 💾"
			@echo "$(END)compiled successfully 💾$(END)"

%.o: %.cpp %.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re