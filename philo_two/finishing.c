/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:15:59 by kallard           #+#    #+#             */
/*   Updated: 2020/12/11 11:05:00 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	wait_eat_cycles(t_setup *setup)
{
	while (setup->count_eating_philos > 0)
	{
		if (setup->one_died == 0)
			usleep(1000);
		else
			break ;
	}
	if (setup->count_eating_philos <= 0)
	{
		pthread_mutex_lock(&(setup->writing));
		write(1, "Each philo has eaten enough times.\n", 35);
		pthread_mutex_unlock(&(setup->writing));
	}
}

static void	wait_one_died(t_setup *setup)
{
	while (!setup->one_died)
		usleep(70);
}

static void	clean(t_setup *setup, t_philo *philos)
{
	int i;

	i = 0;
	free(philos);
	while (i < setup->num_of_philos)
		pthread_mutex_destroy(&(setup->forks[i++]));
	free(setup->forks);
}

int			finishing(t_setup *setup, t_philo *philos)
{
	int	i;

	if (setup->max_eat_cycles)
		wait_eat_cycles(setup);
	else
		wait_one_died(setup);
	i = -1;
	while (++i < setup->num_of_philos)
	{
		pthread_join(philos[i].supervisor, NULL);
		pthread_join(philos[i].thread_id, NULL);
	}
	write(1, "Simulation has ended.\n", 22);
	clean(setup, philos);
	return (0);
}
