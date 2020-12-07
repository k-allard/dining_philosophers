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
	TAKEN_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}					t_action;

typedef struct		s_setup
{
	pthread_mutex_t	*forks;		//вилочные мьютексы = кол-ву философов
	pthread_mutex_t	is_dead;
	pthread_mutex_t	writing; 	//чтобы одновременно не писали статусы
	struct timeval	start;			//время старта симуляции
	int				num_of_philos;	//argv[1]
	uint64_t		time_to_die;	//argv[2] используем тип лонг лонг беззнаковый так как время в МИКРОсекундах
	uint64_t		time_to_eat;	//argv[3]
	uint64_t		time_to_sleep;	//argv[4]
	int				max_eat_cycles;	//argv[5]
	int				can_stop;
	int				one_died;
}					t_setup;

typedef struct		s_philo
{
	int				index;		//порядковый номер философа
	int				num_of_dinners; //сколько раз он уже поел
	t_setup			*setup;
	int				actions[6];
	uint64_t		last_dinner_time;
	int				is_eating;
	pthread_mutex_t eating;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	unsigned int	left_hand;
	unsigned int	right_hand;
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

void		wait_me_2(uint64_t dur);
void		wait_me(struct timeval t, uint64_t start, uint64_t dur);
uint64_t	time_passed(struct timeval start);

/*
** LAUNCH
*/

void	launch_philos(t_setup setup, t_philo *philos);

/*
** PHILO_LIFE
*/
void	eating(t_philo *philo);
void	*philo_entry_function(void *argument);

/*
** SUPERVISOR
*/

void	what_status(t_philo *philo, int time);
void	write_status(int time, int philo_id, char *action, pthread_mutex_t *writing);
void	set_action(t_philo *philo, int action);
void	*supervisor_function(void *argument);

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

#endif
