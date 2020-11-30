#include "philo_one.h"

int ft_strlen(char *str)
{
	int len = 0;

	while(str[len])
		len++;
	return len;
}

void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void put_action_msg(int philo_num, int action)
{
  	struct timeval tv;

  	time_t curtime;
  	gettimeofday(&tv, NULL); 
  	curtime=tv.tv_usec;

	ft_putstr(ft_itoa(philo_num));
	ft_putstr(" ");
	ft_putstr(ft_itoa(tv.tv_usec));

	if (action == TAKEN_FORK)
		write(1, " has taken a fork", 17);
	if (action == EATING)
		write(1, " is eating", 10);
	if (action == SLEEPING)
		write(1, " is sleeping", 12);
	if (action == THINKING)
		write(1, " is thinking", 12);
	if (action == DIED)
		write(1, " died", 17);
}

int main(int argc, char **argv)
{
	pthread_t	thread;
	int 		status;
	int			status_addr;
	t_args		args[ft_atoi(argv[1])];
	if (argc != 5 && argc != 6)
	{
		ft_putstr("main error: wrong number of arguments\n");
		exit(ERROR);
	}
	
	int i = 0;
	while (i < )
	{
		args[i].action = SLEEPING;
		args[philo_num] = i;
		status = pthread_create(&thread, NULL, put_action_msg, &args);
		if (status != SUCCESS)
		{
			ft_putstr("main error: can't create thread\n");
			exit(ERROR);
		}
		i++;
	}
	ft_putstr("Hello from main!\n");

	status = pthread_join(thread, (void**)&status_addr);
	if (status != SUCCESS)
	{
		ft_putstr("main error: can't join thread\n");
		exit(ERROR);
	}

	ft_putstr("\nJoined!\n");
	return 0;
}
