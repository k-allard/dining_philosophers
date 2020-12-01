#include "philo_one.h"

void	launch_philos(t_setup setup, t_philo *philos)
{
	pthread_t thr; // variable to reference the particular thread
	int i;

	i = 0;
	while (i < setup.num_of_philos)
	{
		pthread_create(&thr, NULL, &philo_entry_function, &(philos[i]));
		pthread_detach(thr);
		i++;
	}
}