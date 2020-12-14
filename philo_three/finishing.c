/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:15:59 by kallard           #+#    #+#             */
/*   Updated: 2020/12/14 17:49:33 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		clean(t_setup *setup, t_philo *philos)
{
	free(philos);
	free(setup->p_ids);
	sem_close(setup->sem_for_all_forks);
}

void		finishing(t_setup *setup)
{
	int		i;
	int		stat_loc;
	int		exit_value;

	i = 0;
	while (i < setup->num_of_philos)
	{
		waitpid(-1, &stat_loc, 0);
		if ((WIFEXITED(stat_loc) || WIFSIGNALED(stat_loc)))
		{
			exit_value = WEXITSTATUS(stat_loc);
			if (exit_value == 0)
			{
				while (i < setup->num_of_philos)
				{
					if (i != setup->num_of_philos)
						kill(setup->p_ids[i], SIGTERM);
					i++;
				}
				break ;
			}
			else if (exit_value == 1)
				i++;
		}
	}
}
