#ifndef PHILO_ONE_H
# define MINISHELL_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SUCCESS		0
#define ERROR		1

typedef enum				e_action
{
	TAKEN_FORK = 1,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}							t_action;

/*
** UTILS
*/

char		*ft_itoa(int n);


#endif