/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:35:41 by kallard           #+#    #+#             */
/*   Updated: 2020/12/11 10:23:57 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define SUCCESS	0
# define ERROR		1

typedef enum		e_action
{
	TAKEN_FORK = 0,
	EATING,
	FINISHED_EATING,
	FINISHED_SLEEPING,
	SLEEPING,
	THINKING,
	DIED,
	TAKEN_FORK_LEFT,
	TAKEN_FORK_RIGHT
}					t_action;

typedef struct		s_setup
{
	int				num_of_philos;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				max_eat_cycles;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t decreasing_count_eating_philos;
	struct timeval	start;
	int				count_eating_philos;
	int				one_died;
}					t_setup;

typedef struct		s_philo
{
	int				index;
	int				num_of_dinners;
	t_setup			*setup;
	int				actions[10];
	uint64_t		last_dinner_time;
	uint64_t		next_event_time;
	uint64_t		expected_dead_time;
	int				is_eating;
	int				is_dead;
	pthread_mutex_t eating;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	wait_dead;
	unsigned int	left_hand;
	unsigned int	right_hand;
	pthread_t		thread_id;
	pthread_t		supervisor;
}					t_philo;

/*
** INITS
*/

void				init_setup_struct(t_setup *setup, int argc, char **argv);
void				init_philo_structs(t_philo *philos, t_setup *setup);

/*
** TIME
*/

void				wait_me_2(uint64_t dur, t_setup *setup);
void				wait_me(uint64_t start, t_setup *setup);
void				wait_me_sleeping(uint64_t start, t_setup *setup);
uint64_t			time_passed(struct timeval start);

/*
** LAUNCH
*/

void				launch_philos(t_setup *setup, t_philo *philos);

/*
** PHILO_LIFE
*/
void				eating(t_philo *philo);
void				*philo_entry_function(void *argument);

/*
** SUPERVISOR
*/

void				what_status(t_philo *philo, int time);
void				write_status(int time, t_philo *philo, char *action);
void				write_wait_next_check(int time, t_philo *philo, \
					int next_check_time);
void				set_action(t_philo *philo, int action);
void				*supervisor_function(void *argument);
void				print_status(t_action action, t_philo *philo);

/*
** UTILS
*/

char				*ft_itoa(int n);
int					ft_atoi(char *str);
int					ft_strlen(char *str);
void				ft_putnbr(int n);

/*
** ERRORS
*/

void				init_error(void);
void				args_error(void);
void				malloc_error(void);

/*
** FINISHING
*/

int					finishing(t_setup *setup, t_philo *philos);

#endif
