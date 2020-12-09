#include "philo_one.h"

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	lock_forks(t_philo *philo)
{
	if (!(philo->index % 2))
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	philo->actions[TAKEN_FORK] = 1;
	what_status(philo, time_passed(philo->setup->start) / 1000);
	if (philo->index % 2)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	philo->actions[TAKEN_FORK] = 1;
	what_status(philo, time_passed(philo->setup->start) / 1000);
}

void	eating(t_philo *philo)
{
	if (!philo->setup->one_died)
	{
		pthread_mutex_lock(&philo->eating);
		philo->actions[EATING] = 1;
		what_status(philo, time_passed(philo->setup->start) / 1000);
		philo->last_dinner_time = time_passed(philo->setup->start);
		wait_me_eating(philo->last_dinner_time, philo->setup);
		pthread_mutex_unlock(&philo->eating);
		philo->num_of_dinners++;
	}
}

void	one_philo_ate_enought(t_philo *philo)
{
	pthread_mutex_lock(&philo->setup->decreasing_count_eating_philos);
	philo->setup->count_eating_philos--;
	pthread_mutex_unlock(&philo->setup->decreasing_count_eating_philos);
}

int		max_cycles_reached(t_philo *philo)
{
	if (philo->setup->max_eat_cycles && philo->num_of_dinners >= philo->setup->max_eat_cycles)
	{
		one_philo_ate_enought(philo);
		return (1);
	}
	return (0);
}

void	*philo_entry_function(void *argument) // When creating a thread, we need to point it to a function for it to start execution.
// The function must return void * and take a single void * argument.
{
	t_philo *philo;
	pthread_t supervisor;

	philo = argument;
	pthread_create(&supervisor, NULL, &supervisor_function, argument);
	pthread_detach(supervisor);
	while (42 && !philo->setup->one_died && philo->setup->count_eating_philos)
	{
		lock_forks(philo);
		eating(philo);
		unlock_forks(philo);
		if (philo->setup->one_died || max_cycles_reached(philo))
			break ;
		philo->actions[SLEEPING] = 1;
		what_status(philo, time_passed(philo->setup->start) / 1000);
		wait_me_2(philo->setup->time_to_sleep, philo->setup);
		if (philo->setup->one_died || philo->setup->count_eating_philos == 0)
			break ;
		philo->actions[THINKING] = 1;
		what_status(philo, time_passed(philo->setup->start) / 1000);
	}

	return (NULL);
}
