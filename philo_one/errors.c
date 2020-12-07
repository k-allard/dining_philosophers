#include "philo_one.h"

void		init_error(void)
{
	char *string;
	
	string = "ERROR: Cannot initialize simulation\n";
	write(2, string, ft_strlen(string));
	exit(1);
}

void		args_error(void)
{
	char *string;
	
	string = "ERROR: Wrong arguments\n";
	write(2, string, ft_strlen(string));
	exit(1);
}

void		malloc_error(void)
{
	char *string;
	
	string = "ERROR: Memory allocation error\n";
	write(2, string, ft_strlen(string));
	exit(1);
}
