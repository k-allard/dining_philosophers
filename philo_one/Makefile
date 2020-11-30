NAME = philo_one

SRCS = philo_one.c \
		utils.c

OBJS = $(SRCS:.c=.o)

# FLAGS =-Wall -Wextra -Werror -O3
FLAGS =-g

all: $(NAME)

$(NAME):
	@echo "\x1b[33m Preparing philo_one...\x1b[0m"
	@gcc -o $(NAME) $(SRCS) $(FLAGS)
	@echo "\x1b[32m Philo_one is ready!\x1b[0m"
	@echo "\x1b[32m 4 or 5 arguments are required\x1b[0m"

norm:
	@echo "\x1b[33m Sources NORM CHECK...\x1b[0m"
	@norminette srcs/*.c srcs/parser/*.c srcs/t_lexema/*.c srcs/commands/*.c
	@echo "\n\x1b[33m Headers NORM CHECK...\x1b[0m"
	@norminette srcs/minishell.h srcs/parser/parser.h


clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)


re: fclean all
	@./${NAME} 4 410 200 200 5

test: re


%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

.PHONY:	all clean fclean re
