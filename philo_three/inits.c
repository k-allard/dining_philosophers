/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:01:14 by kallard           #+#    #+#             */
/*   Updated: 2020/12/14 17:25:39 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	open_semaphores(t_setup *setup)
{
	setup->sem_for_all_forks = sem_open("/forks", O_CREAT, S_IRWXU, \
										setup->num_of_philos);
	if (setup->sem_for_all_forks == SEM_FAILED)
		init_error();
	sem_unlink("/forks");
	setup->sem_for_writing = sem_open("/writing", O_CREAT, S_IRWXU, 1);
	if (setup->sem_for_writing == SEM_FAILED)
		init_error();
	sem_unlink("/writing");
	setup->sem_for_decreasing_count_eating_philos = \
		sem_open("/decreasing", O_CREAT, S_IRWXU, 1);
	if (setup->sem_for_decreasing_count_eating_philos == SEM_FAILED)
		init_error();
	sem_unlink("/decreasing");
}

void		init_setup_struct(t_setup *setup, int argc, char **argv)
{
	setup->num_of_philos = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]) * 1000;
	setup->time_to_eat = ft_atoi(argv[3]) * 1000;
	setup->time_to_sleep = ft_atoi(argv[4]) * 1000;
	setup->max_eat_cycles = argc == 6 ? ft_atoi(argv[5]) : 0;
	setup->one_died = 0;
	setup->count_eating_philos = setup->num_of_philos;
	open_semaphores(setup);
	if (gettimeofday(&setup->start, NULL))
		init_error();
	setup->start.tv_usec = (setup->start.tv_usec / 1000) * 1000;
}

static void	init_philo_structs2(t_philo *philos, t_setup *setup)
{
	int	i;
	int j;

	i = 0;
	while (i < setup->num_of_philos)
	{
		j = 0;
		while (j < 10)
			philos[i].actions[j++] = 0;
		philos[i].sem_for_eating = \
								sem_open("/eating", O_CREAT, S_IRWXU, 1);
		if (philos[i].sem_for_eating == SEM_FAILED)
			init_error();
		sem_unlink("/eating");
		philos[i].sem_for_wait_dead = \
								sem_open("/wait_dead", O_CREAT, S_IRWXU, 1);
		if (philos[i].sem_for_wait_dead == SEM_FAILED)
			init_error();
		sem_unlink("/wait_dead");
		i++;
	}
}

void		init_philo_structs(t_philo *philos, t_setup *setup)
{
	int			i;
	uint64_t	start_time;

	start_time = (time_passed(setup->start) / 1000) * 1000 + 0;
	i = 0;
	while (i < setup->num_of_philos)
	{
		philos[i].index = i + 1;
		philos[i].setup = setup;
		philos[i].is_dead = 0;
		philos[i].max_eat_cycles = setup->max_eat_cycles;
		philos[i].num_of_dinners = 0;
		philos[i].last_dinner_time = start_time;
		philos[i].next_event_time = 0;
		philos[i].expected_dead_time = philos[i].last_dinner_time + \
										setup->time_to_die + 800;
		i++;
	}
	init_philo_structs2(philos, setup);
}
