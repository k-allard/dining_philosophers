#include "philo_one.h"

// argvs : number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]
void	init_setup_struct(t_setup *setup, int argc, char **argv)
{
	setup->num_of_philos = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	setup->max_eat_cycles = argc == 6 ?  ft_atoi(argv[5]) : 0;

//	pthread_mutex_init(&(setup->   ), NULL);
//	pthread_mutex_lock(&(setup->   ));
}