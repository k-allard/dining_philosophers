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

	ft_putstr(ft_itoa(tv.tv_usec));
	ft_putstr(" ");
	ft_putstr(ft_itoa(philo_num));


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

void	*printing_message(void *philo_num)
{
	struct timeval tv;

  	time_t curtime;
  	gettimeofday(&tv, NULL); 
  	curtime=tv.tv_usec;

	ft_putstr(ft_itoa(tv.tv_usec));
	ft_putstr(" ");
	ft_putstr(ft_itoa(philo_num));
}

int main(int argc, char **argv)
{
	pthread_t	thread;
	int 		status;
	int			status_addr;

	if (argc != 5 && argc != 6)
	{
		ft_putstr("main error: wrong number of arguments\n");
		exit(ERROR);
	}
	
	int i = 0;
	while (i < 2)
	{
		status = pthread_create(&thread, NULL, printing_message, i);
		if (status != SUCCESS)
		{
			ft_putstr("main error: can't create thread\n");
			exit(ERROR);
		}
	}
	ft_putstr("Hello from main!\n");

	status = pthread_join(thread, (void**)&status_addr);
	if (status != SUCCESS)
	{
		ft_putstr("main error: can't join thread\n");
		exit(ERROR);
	}

	ft_putstr("Joined!\n");
	return 0;
}
