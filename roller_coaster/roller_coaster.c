#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_roller_coaster
{
	sem_t		*sem_id;
}				t_roller_coaster;

void	error(void)
{
	write(1, "Something failed, sorry\n", 24);
	exit(1);
}

void	ride_roller_coaster()
{
	write(1, " Started riding\n", 16);
	usleep(1500000);
	write(1, " *WOOOHOOOOO!*\n", 15);
	usleep(1500000);
	write(1, " Finished riding\n", 17);
}

void	*visitor_actions(void *args)
{
	t_roller_coaster	*roller_coaster;

	roller_coaster = (t_roller_coaster *)args;
	write(1, " I am here to ride\n", 19);
   	sem_wait(roller_coaster->sem_id);
	ride_roller_coaster();
	sem_post(roller_coaster->sem_id);

	return (NULL);
}

int main(void)
{
	pthread_t			tid[10];
	int					i;
	int					err;
	t_roller_coaster	roller_coaster;

write(1, "\n 1   2    3   4    5    6    7   8    9   10\n", 47);
write(1, " ☻ . ☻ .  ☻ . ☻  . ☻ .  ☻ .  ☻ . ☻ .  ☻ .  ☻ .\n", 68);
write(1, "/█\\./█\\../█\\./█\\../█\\../█\\../█\\./█\\../█\\../█\\.\n", 68);
write(1, "╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬-||--╬╬╬╬╬╬╬╬╬╬╬╬╬╬\n", 130);
write(1, "══════════════════════════════════════════════\n", 140);
write(1, "  1    2     3\n", 16);
write(1, "┏┳┳┳┓┏┳┳┳┳┓┏┳┳┳┳┓ \n", 54);
write(1, "┃╋┻┻┫┣┻╋╋┻┫┣┻╋╋┻┫ \n", 54);
write(1, "┗┻━ⓞ ┻┻ⓞ ┻┻ⓞ ┻┻ⓞ  \n\n", 47);
write(1, "══════════════════════════════════════════════\n", 140);
write(1, "                                by kallard (♥)\n", 50);


    roller_coaster.sem_id = sem_open("/car_places", O_CREAT, S_IRWXU, 3);
    if (roller_coaster.sem_id == SEM_FAILED)
       error();
	sem_unlink("/car_places");
	i = -1;
	while (++i < 10)
	{
        err = pthread_create(&tid[i], NULL, &visitor_actions, &roller_coaster);
        if (err)
        	error();
	}
	i = -1;
	while (++i < 10)
        pthread_join(tid[i], NULL);
	write(1, " _______________________\n 10 visitors had a ride!\n", 50);
	sem_close(roller_coaster.sem_id);
    return (0);
}
