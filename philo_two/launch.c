/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:27:18 by kallard           #+#    #+#             */
/*   Updated: 2020/12/14 21:06:26 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	launch_three_philos(t_philo *philos)
{
	pthread_create(&(philos[0].thread_id), NULL, \
							&philo_entry_function, &(philos[0]));
	usleep(1000);
	pthread_create(&(philos[1].thread_id), NULL, \
							&philo_entry_function, &(philos[1]));
	usleep(1000);
	pthread_create(&(philos[2].thread_id), NULL, \
							&philo_entry_function, &(philos[2]));
}

void		launch_philos(t_setup *setup, t_philo *philos)
{
	int i;

	if (setup->num_of_philos == 3)
		launch_three_philos(philos);
	else
	{
		i = -1;
		while (++i < setup->num_of_philos)
			if (!(i % 2))
				pthread_create(&(philos[i].thread_id), NULL, \
								&philo_entry_function, &(philos[i]));
		i = -1;
		usleep(10000);
		while (++i < setup->num_of_philos)
			if (i % 2)
				pthread_create(&(philos[i].thread_id), NULL, \
								&philo_entry_function, &(philos[i]));
	}
}
