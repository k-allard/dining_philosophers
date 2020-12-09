#include "philo_one.h"

void	check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i] && argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				args_error();
			j++;
		}
		i++;
	}
}

void	wait_eat_cycles(t_setup	*setup)
{
	int i;

	i = 0;
	while (setup->count_eating_philos > 0)
	{
		if(setup->one_died == 0)
			usleep(70);
		else
			 break ;
	}
	if (!setup->count_eating_philos)
	{
		pthread_mutex_lock(&(setup->writing));
		write(1, "Each philo has eaten enough times.\n", 35);
		pthread_mutex_unlock(&(setup->writing));
	}
}

void wait_one_died(t_setup	*setup)
{
	while (!setup->one_died)
	{
		usleep(70);
	}
}

void	clean(t_setup *setup, t_philo *philos)
{
	int i;

	i = 0;
	free(philos);
	while (i < setup->num_of_philos)
		pthread_mutex_destroy(&(setup->forks[i++]));
	free(setup->forks);
}

int main(int argc, char **argv)
{
    t_setup	setup;		//структура настроек
	t_philo	*philos;	//структуры для философов
	int		i;

	if (argc != 5 && argc != 6)
		args_error();
	check_args(argc, argv);
	init_setup_struct(&setup, argc, argv);
	gettimeofday(&setup.start, NULL);
	philos = malloc(sizeof(t_philo) * setup.num_of_philos);	//выделяем память под структуры философов
	i = 0;
	while (i < setup.num_of_philos)
		pthread_mutex_init(&(setup.forks[i++]), NULL);	//вилочные мьютексы = кол-ву философов
	init_philo_structs(philos, &setup);
	launch_philos(setup, philos);
	if (setup.max_eat_cycles)
		wait_eat_cycles(&setup);
	else
		wait_one_died(&setup);
	
	pthread_mutex_lock(&(setup.writing));
	write(1, "Simulation has ended.\n", 22);
	pthread_mutex_unlock(&(setup.writing));
	clean(&setup, philos);
}
