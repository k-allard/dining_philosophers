NAME = roller_coaster

SRCS = roller_coaster.c

OBJS = $(SRCS:.c=.o)

FLAGS =-Wall -Wextra -Werror -O3
#FLAGS = -fsanitize=address -g

all: $(NAME)

$(NAME):
	@echo "\x1b[33m Preparing roller_coaster...\x1b[0m"
	@gcc -o $(NAME) $(SRCS) $(FLAGS)
	@echo "\x1b[32m ./roller_coaster is ready!\x1b[0m"
	@./$(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)


re: fclean all

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

.PHONY:	all clean fclean re
