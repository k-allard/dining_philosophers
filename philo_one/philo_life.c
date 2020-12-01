#include "philo_one.h"

void	*philo_entry_function(void *argument) // When creating a thread, we need to point it to a function for it to start execution.
// The function must return void * and take a single void * argument.
{
	t_philo *philo;
	pthread_t supervisor;

	philo = argument;
	pthread_create(&supervisor, NULL, &supervisor_function, argument);
	pthread_detach(supervisor);
	while (42 && !philo->setup->can_stop)
	{
		philo->alerts[THINKING] = 1;
	}



	return (NULL);
}
