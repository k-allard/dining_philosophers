/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 21:37:59 by kallard           #+#    #+#             */
/*   Updated: 2020/12/11 11:05:30 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

uint64_t	time_passed(struct timeval start)
{
	struct timeval	now;
	uint64_t		t;

	gettimeofday(&now, 0);
	t = (now.tv_sec - start.tv_sec);
	t = t * 1000000;
	t += (now.tv_usec - start.tv_usec);
	return (t);
}

void		wait_me(uint64_t stop_eat, t_setup *setup)
{
	while (time_passed(setup->start) < stop_eat)
		usleep(100);
}
