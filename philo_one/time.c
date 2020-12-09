#include "philo_one.h"

uint64_t	time_passed(struct timeval start)	//сколько прошло МИКРОсекунд со времени в аргументе
{
	struct timeval now;

	gettimeofday(&now, 0);
	return ((now.tv_sec - start.tv_sec) * 1000000 + (now.tv_usec - start.tv_usec));
}

void		wait_me_2(uint64_t dur, t_setup *setup)
{
	struct timeval now;
	gettimeofday(&now, 0);
	while (time_passed(now) < dur && setup->count_eating_philos && !setup->one_died)
		usleep(1);
}

void		wait_me_eating(uint64_t start, t_setup *setup)
{
	uint64_t to_wait;

	to_wait = start + setup->time_to_eat;
	while (time_passed(setup->start) < to_wait && setup->count_eating_philos && !setup->one_died)
		usleep(1);
}
