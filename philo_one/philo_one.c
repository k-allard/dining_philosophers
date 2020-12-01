#include "philo_one.h"

int ft_strlen(char *str)
{
	int len = 0;

	while(str[len])
		len++;
	return len;
}

void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void put_action_msg(int philo_num, int action)
{
  	struct timeval tv;

  	time_t curtime;
  	gettimeofday(&tv, NULL); 
  	curtime=tv.tv_usec;

	ft_putstr(ft_itoa(philo_num));
	ft_putstr(" ");
	ft_putstr(ft_itoa(tv.tv_usec));

	if (action == TAKEN_FORK)
		write(1, " has taken a fork", 17);
	if (action == EATING)
		write(1, " is eating", 10);
	if (action == SLEEPING)
		write(1, " is sleeping", 12);
	if (action == THINKING)
		write(1, " is thinking", 12);
	if (action == DIED)
		write(1, " died", 17);
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
//	while (i < )
//	{
//		args[i].action = SLEEPING;
//		args[philo_num] = i;
//		status = pthread_create(&thread, NULL, put_action_msg, &args);
//		if (status != SUCCESS)
//		{
//			ft_putstr("main error: can't create thread\n");
//			exit(ERROR);
//		}
//		i++;
//	}
//	ft_putstr("Hello from main!\n");
//
//	status = pthread_join(thread, (void**)&status_addr);
//	if (status != SUCCESS)
//	{
//		ft_putstr("main error: can't join thread\n");
//		exit(ERROR);
//	}
//
//	ft_putstr("\nJoined!\n");
//	return 0;
}
