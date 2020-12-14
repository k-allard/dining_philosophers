/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:27:18 by kallard           #+#    #+#             */
/*   Updated: 2020/12/14 11:17:45 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	launch_philos(t_setup *setup, t_philo *philo, int num)
{
	int 	i;
	pid_t	pid;
	
	i = -1;
	while (++i < setup->num_of_philos)
	{
		if ((philo->p_id = fork()) < 0)
			init_error();
		else if (philo->p_id == 0)
		{
			philo_entry_function(philo);
			// if(dead)
			// 	exit(1);
			// else
			// 	exit(2);
		}
		else
		{
			//sem_wait("/wait_dead_or_max_eating");
		}
	}
}
