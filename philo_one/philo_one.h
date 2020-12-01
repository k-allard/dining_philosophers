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
	unsigned  int	num_of_philos;	//argv[1]
	unsigned  int	time_to_die;	//argv[2]
	unsigned  int	time_to_eat;	//argv[3]
	unsigned  int	time_to_sleep;	//argv[4]
	unsigned  int	max_eat_cycles;	//argv[5]
}					t_setup;

typedef struct		s_philo
{
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

/*
** LAUNCH
*/

/*
** UTILS
*/

char				*ft_itoa(int n);
int					ft_atoi(char *str);



#endif