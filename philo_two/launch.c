/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:27:18 by kallard           #+#    #+#             */
/*   Updated: 2020/12/11 11:05:04 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	launch_philos(t_setup *setup, t_philo *philos)
{
	int i;

	i = -1;
	while (++i < setup->num_of_philos)
		if (!(i % 2))
			pthread_create(&(philos[i].thread_id), NULL, \
							&philo_entry_function, &(philos[i]));
	i = -1;
	while (++i < setup->num_of_philos)
		if (i % 2)
			pthread_create(&(philos[i].thread_id), NULL, \
							&philo_entry_function, &(philos[i]));
}
