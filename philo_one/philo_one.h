#ifndef PHILO_ONE_H
# define MINISHELL_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SUCCESS		0
#define ERROR		1

typedef enum		e_action
{
	TAKEN_LEFT_FORK,
	TAKEN_RIGHT_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}					t_action;

typedef struct		s_setup
{
	pthread_mutex_t	*forks;	//вилочные мьютексы = кол-ву философов

	struct timeval	start;			//время старта симуляции
	int				num_of_philos;	//argv[1]
	uint64_t		time_to_die;	//argv[2] используем тип лонг лонг беззнаковый так как время в МИКРОсекундах
	uint64_t		time_to_eat;	//argv[3]
	uint64_t		time_to_sleep;	//argv[4]
	int				max_eat_cycles;	//argv[5]
	int				can_stop;
}					t_setup;

typedef struct		s_philo
{
	int				index;		//порядковый номер философа
	t_setup			*setup;
	int				actions[6];

}					t_philo;

typedef struct		s_message 
{
	int				time;
	int				philo_num;
    t_action		action;
}					t_message;

/*
** INITS
*/

void	init_setup_struct(t_setup *setup, int argc, char **argv);
void	init_philo_structs(t_philo *philos, t_setup *setup);

/*
** TIME
*/

uint64_t	time_passed(struct timeval start);

/*
** LAUNCH
*/

void	launch_philos(t_setup setup, t_philo *philos);

/*
** PHILO_LIFE
*/

void	*philo_entry_function(void *argument);

/*
** SUPERVISOR
*/

/*
** UTILS
*/

char				*ft_itoa(int n);
int					ft_atoi(char *str);



#endif