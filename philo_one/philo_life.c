/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 22:59:05 by kallard           #+#    #+#             */
/*   Updated: 2020/12/10 23:00:32 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	lock_forks(t_philo *philo)
{
	if (!(philo->index % 2))
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(TAKEN_FORK_RIGHT, philo);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&philo->eating);
		philo->last_dinner_time = \
				(time_passed(philo->setup->start) / 1000) * 1000;
		print_status(TAKEN_FORK_LEFT, philo);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(TAKEN_FORK_LEFT, philo);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&philo->eating);
		philo->last_dinner_time = \
				(time_passed(philo->setup->start) / 1000) * 1000;
		print_status(TAKEN_FORK_RIGHT, philo);
	}
}

void	eating(t_philo *philo)
{
	lock_forks(philo);
	print_status(EATING, philo);
	philo->expected_dead_time = philo->last_dinner_time + \
								philo->setup->time_to_die + 900;
	philo->next_event_time = philo->last_dinner_time + \
							philo->setup->time_to_eat + 100;
	philo->num_of_dinners++;
	if (philo->setup->max_eat_cycles && philo->num_of_dinners >= \
										philo->setup->max_eat_cycles)
	{
		pthread_mutex_lock(&(philo->setup->decreasing_count_eating_philos));
		philo->setup->count_eating_philos--;
		pthread_mutex_unlock(&(philo->setup->decreasing_count_eating_philos));
	}
	wait_me(philo->next_event_time, philo->setup);
	philo->next_event_time = philo->next_event_time + \
							philo->setup->time_to_sleep + 300;
	unlock_forks(philo);
}

void	*philo_entry_function(void *argument)
{
	t_philo	*philo;

	philo = argument;
	pthread_create(&(philo->supervisor), NULL, &supervisor_function, argument);
	while (42 && !philo->setup->one_died && \
			philo->setup->count_eating_philos > 0)
	{
		eating(philo);
		if (philo->setup->one_died || philo->setup->count_eating_philos <= 0)
			break ;
		print_status(SLEEPING, philo);
		wait_me(philo->next_event_time, philo->setup);
		print_status(THINKING, philo);
	}
	return (NULL);
}
