/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 21:29:03 by kallard           #+#    #+#             */
/*   Updated: 2020/12/12 20:27:13 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	write_died_status(int time, int index, char *status)
{
	ft_putnbr(time);
	write(1, "\t", 1);
	ft_putnbr(index);
	write(1, status, ft_strlen(status));
}

static void	died(t_philo *philo, uint64_t time)
{
	philo->is_dead = 1;
	philo->setup->one_died = 1;
	philo->actions[DIED] = 1;
	sem_wait(philo->setup->sem_for_writing);
	write_died_status(time / 1000, philo->index, " died\n");
	sem_post(philo->setup->sem_for_writing);
}

void		print_status(t_action action, t_philo *philo)
{
	char	*actions[9];
	int		time;

	actions[TAKEN_FORK] = " has taken a fork\n";
	actions[EATING] = " is eating\n";
	actions[FINISHED_EATING] = " is eating Stop\n";
	actions[FINISHED_SLEEPING] = " is sleeping Stop\n";
	actions[SLEEPING] = " is sleeping\n";
	actions[THINKING] = " is thinking\n";
	actions[DIED] = " is dead\n";
	actions[TAKEN_FORK_LEFT] = " has taken a fork Left\n";
	actions[TAKEN_FORK_RIGHT] = " has taken a fork Rigth\n";
	time = time_passed(philo->setup->start) / 1000;
	sem_wait(philo->setup->sem_for_writing);
	if (!philo->setup->one_died && philo->setup->count_eating_philos > 0)
	{
		ft_putnbr(time);
		write(1, "\t", 1);
		ft_putnbr(philo->index);
		write(1, actions[action], ft_strlen(actions[action]));
	}
	sem_post(philo->setup->sem_for_writing);
}

/*
** Supervisor of each philo
** Kills the philo if he hasn't eaten before time_to_die
*/

void		*supervisor_function(void *argument)
{
	t_philo		*philo;
	uint64_t	time;
	int			last_number_of_dinners;

	philo = argument;
	while (42 && !philo->setup->one_died && \
		philo->setup->count_eating_philos > 0 && !philo->is_dead)
	{
		last_number_of_dinners = philo->num_of_dinners;
		wait_me(philo->expected_dead_time, philo->setup);
		time = time_passed(philo->setup->start);
		sem_wait(philo->sem_for_eating);
		if (!philo->setup->one_died && philo->setup->count_eating_philos > 0 \
			&& last_number_of_dinners == philo->num_of_dinners)
		{
			died(philo, time);
			sem_post(philo->sem_for_eating);
			break ;
		}
		sem_post(philo->sem_for_eating);
	}
	return (NULL);
}
