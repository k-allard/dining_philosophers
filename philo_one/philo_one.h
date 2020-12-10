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
	TAKEN_FORK = 0,
	EATING,
//extra_chacks vvv
	FINISHED_EATING,
	FINISHED_SLEEPING,
//extra_chacks ^^^
	SLEEPING,
	THINKING,
	DIED,
	TAKEN_FORK_LEFT,
	TAKEN_FORK_RIGHT
}					t_action;


typedef struct		s_setup
{

	
	int				num_of_philos;	//argv[1]
	uint64_t		time_to_die;	//argv[2] используем тип лонг лонг беззнаковый так как время в МИКРОсекундах
	uint64_t		time_to_eat;	//argv[3]
	uint64_t		time_to_sleep;	//argv[4]
	int				max_eat_cycles;	//argv[5]

	pthread_mutex_t	*forks;		//вилочные мьютексы = кол-ву философов
	pthread_mutex_t	writing; 	//чтобы одновременно не писали статусы
	pthread_mutex_t decreasing_count_eating_philos;
	struct timeval	start;		//время старта симуляции
	int				count_eating_philos;
	int				one_died;	//один из философов умер
}					t_setup;

typedef struct		s_philo
{
	int				index;		//порядковый номер философа
	int				num_of_dinners; //сколько раз он уже поел
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

void	init_setup_struct(t_setup *setup, int argc, char **argv);
void	init_philo_structs(t_philo *philos, t_setup *setup);

/*
** TIME
*/

void		wait_me_2(uint64_t dur, t_setup *setup);
void		wait_me(uint64_t start, t_setup *setup);
void		wait_me_sleeping(uint64_t start, t_setup *setup);
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
void	write_status(int time, t_philo *philo, char *action);
void	write_wait_next_check(int time, t_philo *philo, int next_check_time);
void	set_action(t_philo *philo, int action);
void	*supervisor_function(void *argument);
void	print_status(t_action action, t_philo *philo);

/*
** UTILS
*/

char				*ft_itoa(int n);
int					ft_atoi(char *str);
int					ft_strlen(char *str);
void				ft_putnbr(int n);
size_t	ft_cpy(char *dest, const char *src);
/*
** ERRORS
*/

void				init_error(void);
void				args_error(void);
void				malloc_error(void);

#endif
