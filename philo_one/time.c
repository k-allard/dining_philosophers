#include "philo_one.h"

uint64_t	time_passed(struct timeval start)	//сколько прошло МИКРОсекунд со старта программы
{
	struct timeval now;

	gettimeofday(&now, 0);
	return ((now.tv_sec - start.tv_sec) * 1000000 + (now.tv_usec - start.tv_usec));
}

