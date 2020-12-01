#include "philo_one.h"

// argvs : number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]
void	init_setup_struct(t_setup *setup, int argc, char **argv)
{
	setup->num_of_philos = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	setup->max_eat_cycles = argc == 6 ?  ft_atoi(argv[5]) : 0;
	setup->forks = malloc(sizeof(pthread_mutex_t) * (setup->num_of_philos));
//	pthread_mutex_init(&(setup->   ), NULL);
//	pthread_mutex_lock(&(setup->   ));
}

void	init_philo_structs(t_philo *philos, t_setup *setup)
{
	int i;
	int j;

	i = 0;
	while (i < setup->num_of_philos)
	{
		philos[i].index = i + 1;
		philos[i].setup = setup;
		j = 0;
		while (j < 6)
			philos[i].actions[j++] = 0;

		i++;
	}
}