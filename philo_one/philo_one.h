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

}					t_setup;

typedef struct		s_message 
{
	int				time;
	int				philo_num;
    t_action		action;
}					t_message;

/*
** UTILS
*/

char				*ft_itoa(int n);


#endif