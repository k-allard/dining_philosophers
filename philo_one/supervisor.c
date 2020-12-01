#include "philo_one.h"



void	*supervisor_function(void *argument)
{
	t_philo *philo;
	uint64_t	time; // в микросекундах

	philo = argument;
	while (1 && !philo->setup->can_stop)
	{
		time = time_passed(philo->setup->start); 	//сколько прошло МИКРОсекунд со старта программы

	}
	return (NULL);
}