#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS		0
#define ERROR		1

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

void	*printing_message(void *args)
{
	ft_putstr("Hello from thread!\n");
	getchar();
	return SUCCESS;
}

int main(int argc, char **argv)
{
	pthread_t	thread;
	int 		status;
	int			status_addr;

	if (argc != 5 || argc != 6)
	{
		ft_putstr("main error: wrong number of arguments\n");
		exit(ERROR);
	}
	

	status = pthread_create(&thread, NULL, printing_message, NULL);
	if (status != SUCCESS)
	{
		ft_putstr("main error: can't create thread\n");
		exit(ERROR);
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
