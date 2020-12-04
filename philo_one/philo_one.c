#include "philo_one.h"

//int ft_strlen(char *str)
//{
//	int len = 0;
//
//	while(str[len])
//		len++;
//	return len;
//}
//
//void ft_putstr(char *str)
//{
//	write(1, str, ft_strlen(str));
//}
//
//void put_action_msg(int philo_num, int action)
//{
//  	struct timeval tv;
//
//  	time_t curtime;
//  	gettimeofday(&tv, NULL);
//  	curtime=tv.tv_usec;
//
//	ft_putstr(ft_itoa(philo_num));
//	ft_putstr(" ");
//	ft_putstr(ft_itoa(tv.tv_usec));
//
//	if (action == TAKEN_FORK)
//		write(1, " has taken a fork", 17);
//	if (action == EATING)
//		write(1, " is eating", 10);
//	if (action == SLEEPING)
//		write(1, " is sleeping", 12);
//	if (action == THINKING)
//		write(1, " is thinking", 12);
//	if (action == DIED)
//		write(1, " died", 17);
//}

void	wait_eat_cycles(t_philo *philos)
{
	int i;

	i = 0;
	while (i < philos->setup->num_of_philos)
	{
		pthread_mutex_lock(&(philos[i].has_eaten_enough_times));
		pthread_mutex_unlock(&(philos[i].has_eaten_enough_times));
		i++;
	}
	pthread_mutex_unlock(&philos->setup->writing);
	pthread_mutex_lock(&(philos->setup->writing));
	if (!philos->setup->one_died)
		write(1, "Each philo has eaten enough times.\n", 35);
	pthread_mutex_unlock(&(philos->setup->writing));
	pthread_mutex_unlock(&(philos->setup->is_dead));
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
    t_setup		setup;		//структура настроек
	t_philo		*philos;	//структуры для философов
	int i;

	init_setup_struct(&setup, argc, argv);
	philos = malloc(sizeof(t_philo) * setup.num_of_philos);	//выделяем память под структуры философов
	i = 0;
	while (i < setup.num_of_philos)
		pthread_mutex_init(&(setup.forks[i++]), NULL);	//вилочные мьютексы = кол-ву философов
	init_philo_structs(philos, &setup);
	gettimeofday(&setup.start, NULL);
	launch_philos(setup, philos);
	if (setup.max_eat_cycles)
		wait_eat_cycles(philos);
	pthread_mutex_lock(&(setup.is_dead));
	pthread_mutex_unlock(&(setup.is_dead));
	clean(&setup, philos);
	write(1, "Simulation has ended.\n", 22);
}
