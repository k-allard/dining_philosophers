/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:15:59 by kallard           #+#    #+#             */
/*   Updated: 2020/12/14 12:55:56 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
	// {
	// 	sem_wait(setup->sem_for_writing);
		write(1, "Each philo has eaten enough times.\n", 35);
		// sem_post(setup->sem_for_writing);
	// }
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
	sem_close(setup->sem_for_all_forks);
}

int			finishing(t_setup *setup, t_philo *philos)
{
	int	
	while (i < simulation->number_of_philosopher)
	{
		waitpid(-1, &status, 0);
		if ((WIFEXITED(status) || WIFSIGNALED(status)))
		{
			if ((status_value = WEXITSTATUS(status)) == 0)	//death
			{
				while (i < simulation->number_of_philosopher)
				{
					if (i != simulation->number_of_philosopher)
						kill(simulation->philos_pid[i], SIGTERM);
					i++;
				}
				break ;
			}
			else if (status_value == 1)
				i++;
		}
	}
	return (__SUCCESS);
	write(1, "Simulation has ended.\n", 22);
	clean(setup, philos);
	return (0);
}
