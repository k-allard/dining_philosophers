/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:27:18 by kallard           #+#    #+#             */
/*   Updated: 2020/12/14 15:01:30 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	launch_philos(t_philo *philo, pid_t	*p_ids, int num)
{
	pid_t	pid;
	
	if ((pid = fork()) < 0)
		init_error();
	else if (pid == 0)
		philo_entry_function(philo);
	else
		p_ids[num] = pid;
}
