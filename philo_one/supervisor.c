#include "philo_one.h"

void	write_died_status(int time, int index, char *status)
{
	ft_putnbr(time);
	write(1, "\t", 1);
	ft_putnbr(index);
	write(1, status, ft_strlen(status));
}

void	died(t_philo *philo, uint64_t time)
{
	philo->is_dead = 1;
	philo->setup->one_died = 1;
	set_action(philo, DIED);
	pthread_mutex_lock(&(philo->setup->writing));
	write_died_status(time / 1000, philo->index, " died\n");
	pthread_mutex_unlock(&philo->setup->writing);
}

void	set_action(t_philo *philo, int action)
{
	philo->actions[action] = 1;
}

void	write_status(int time, int philo_id, char *action, pthread_mutex_t *writing)
{
	char *timeS;
	char *idS;
	char *tmp;
	char *str;
	int len;
	timeS = ft_itoa(time);
	idS = ft_itoa(philo_id);
	len = ft_strlen(action) + ft_strlen(timeS) + ft_strlen(idS) + 2;
	str = (char*)malloc(sizeof(char) * len);
	tmp = str + ft_cpy(str, timeS);
	tmp = tmp + ft_cpy(tmp, "\t");
	tmp = tmp + ft_cpy(tmp, idS);
	tmp = tmp + ft_cpy(tmp, action);
	pthread_mutex_lock(writing);
	write(1, str, len-1);
	pthread_mutex_unlock(writing);
	free(timeS);
	free(idS);
	free(str);
}

void	print_status(t_action action, t_philo *philo)
{
	char *actions[9];
	int time;

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
	write_status(time, philo->index, actions[action], &philo->setup->writing);
}

void	what_status(t_philo *philo, int time)
{
	if (philo->setup->one_died)
		return ;
	if (philo->actions[THINKING])
	{
		write_status(time, philo->index, " is thinking\n", &philo->setup->writing);
		philo->actions[THINKING] = 0;
	}
	else if (philo->actions[TAKEN_FORK])
	{
		write_status(time, philo->index, " has taken a fork\n", &philo->setup->writing);
		philo->actions[TAKEN_FORK] = 0;
	}
	else if (philo->actions[EATING])
	{
		write_status(time, philo->index, " is eating\n", &philo->setup->writing);
		philo->actions[EATING] = 0;
	}

//extra_chacks vvv
	else if (philo->actions[FINISHED_EATING])
	{
		write_status(time, philo->index, " finished eating\n", &philo->setup->writing);
		philo->actions[FINISHED_EATING] = 0;
	}
	else if (philo->actions[FINISHED_SLEEPING])
	{
		write_status(time, philo->index, " finished sleeping\n", &philo->setup->writing);
		philo->actions[FINISHED_SLEEPING] = 0;
	}
//extra_chacks ^^^

	else if (philo->actions[SLEEPING])
	{
		write_status(time, philo->index, " is sleeping\n", &philo->setup->writing);
		philo->actions[SLEEPING] = 0;
	}
	else if (philo->actions[DIED])
	{
		write_status(time, philo->index, " is dead\n", &philo->setup->writing);
		philo->actions[DIED] = 0;
		philo->setup->one_died = 1;
	}
}

/*
** Supervisor of each philo
** - kills the philo if he hasnt eaten before time_to_die
*/

void	*supervisor_function(void *argument)
{
	t_philo 	*philo;
	uint64_t	time; // в микросекундах
	uint64_t	t; // в микросекундах

	philo = argument;
	while (42 && !philo->setup->one_died && philo->setup->count_eating_philos)
	{
		if (philo->is_dead)
			break ;
		t = philo->setup->time_to_die - (time_passed(philo->setup->start) - philo->last_dinner_time);
		usleep(t);
		pthread_mutex_lock(&philo->eating);
		time = time_passed(philo->setup->start);
		if(!philo->setup->one_died && time - philo->last_dinner_time > philo->setup->time_to_die)
		{
			died(philo, time);
			break ;
		}
		pthread_mutex_unlock(&philo->eating);
		/*
		time = time_passed(philo->setup->start); 	//сколько прошло МИКРОсекунд со старта программы
		if (time - philo->last_dinner_time > philo->setup->time_to_die && philo->setup->count_eating_philos)
		{
			if (!philo->setup->one_died)
				died(philo, time);
			pthread_mutex_unlock(&philo->eating);
			break ;
		}
		pthread_mutex_unlock(&philo->eating);
		usleep(70);
		*/
	}
	return (NULL);
}
