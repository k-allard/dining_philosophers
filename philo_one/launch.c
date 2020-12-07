#include "philo_one.h"

void	launch_philos(t_setup setup, t_philo *philos)
{
	int i;
	pthread_t thr; // variable to reference the particular thread

	i = -1;
	while (++i < setup.num_of_philos)
	{
		if (!(i % 2))
		{
			pthread_create(&thr, NULL, &philo_entry_function, &(philos[i]));
			pthread_detach(thr);
		}
	}
	i = -1;
	while (++i < setup.num_of_philos)
	{
		if (i % 2)
		{
			pthread_create(&thr, NULL, &philo_entry_function, &(philos[i]));
			pthread_detach(thr);
		}
	}
}
