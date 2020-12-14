NAME = philo_three

SRCS = philo_three.c \
		utils.c \
		inits.c \
		launch.c \
		philo_life.c \
		supervisor.c \
		time.c \
		finishing.c \
		errors.c

OBJS = $(SRCS:.c=.o)

FLAGS =-Wall -Wextra -Werror -O3
#FLAGS = -fsanitize=address -g

all: $(NAME)

$(NAME):
	@echo "\x1b[33m Preparing philo_three...\x1b[0m"
	@gcc -o $(NAME) $(SRCS) $(FLAGS)
	@echo "\x1b[32m ./philo_three is ready!\x1b[0m"
	@echo "\x1b[32m 4 or 5 arguments are required :\x1b[0m"
	@echo "\x1b[32m number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]\x1b[0m"

norm:
	@echo "\x1b[33m Sources NORM CHECK...\x1b[0m"
	@norminette ./*.c
	@echo "\n\x1b[33m Headers NORM CHECK...\x1b[0m"
	@norminette ./*.h


clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test1: re
	@echo "\x1b[33m [5 800 200 200] - no one should die!\x1b[0m"
	@./${NAME} 5 800 200 200

test2: re
	@echo "\x1b[33m [5 800 200 200 4] - no one should die and the simulation should stop when all has eaten 4 times each!\x1b[0m"
	@./${NAME} 5 800 200 200 4

test3: re
	@echo "\x1b[33m [4 410 200 200] - no one should die!\x1b[0m"
	@./${NAME} 4 410 200 200

test4: re
	@echo "\x1b[33m [4 310 200 100] - a philo should die!\x1b[0m"
	@./${NAME} 4 310 200 100

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

.PHONY:	all clean fclean re
