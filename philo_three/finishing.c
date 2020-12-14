/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:15:59 by kallard           #+#    #+#             */
/*   Updated: 2020/12/14 14:54:23 by kallard          ###   ########.fr       */
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
	int		i;
	int		status;
	int		status_value;

	i = 0;
	while (i < setup->num_of_philos)
	{
		waitpid(-1, &status, 0);
		if ((WIFEXITED(status) || WIFSIGNALED(status)))
		{
			if ((status_value = WEXITSTATUS(status)) == 0)	//death
			{
				while (i < setup->num_of_philos)
				{
					if (i != setup->num_of_philos)
						kill(setup->p_ids[i], SIGTERM);
					i++;
				}
				break ;
			}
			else if (status_value == 1)
				i++;
		}
	}	
	i = -1;
	while (++i < setup->num_of_philos)
		pthread_join(philos[i].supervisor, NULL);
	write(1, "Simulation has ended.\n", 22);
	clean(setup, philos);
	return (0);
}
