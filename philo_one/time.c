#include "philo_one.h"

uint64_t	time_passed(struct timeval start)	//сколько прошло МИКРОсекунд со времени в аргументе
{
	struct timeval now;

	gettimeofday(&now, 0);
	return ((now.tv_sec - start.tv_sec) * 1000000 + (now.tv_usec - start.tv_usec));
}

void		wait_me_2(uint64_t dur)
{
	struct timeval now;
	gettimeofday(&now, 0);
	while (elapsed_time(now) < dur)
		usleep(999);
}

void		wait_me(struct timeval t, uint64_t start, uint64_t dur)
{
	uint64_t to_wait;

	to_wait = start + dur;
	while (time_passed(t) < to_wait)
		usleep(999);
}
