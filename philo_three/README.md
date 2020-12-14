# :fork_and_knife: Dining philosophers problem
### _with threads and :vertical_traffic_light: semaphore_
## :star: Permitted functions :  
__memset__, malloc, free, write, __usleep__, __gettimeofday__, __pthread_create__, 
__pthread_detach__, __pthread_join__, __sem_open__, __sem_close__, __sem_post__, __sem_wait__, __sem_unlink__

## :star: Semaphores

- __sem_open__ - initializes and open a named semaphore
- __sem_close__ - closes a named semaphore
- __sem_post__ - unlocks a semaphore == the value of the semaphore is incremented
- __sem_wait__ - locks a semaphore
- __sem_unlink__ - remove a named semaphore

### Semaphore usage

Go to my :arrow_right: [roller coaster problem solution](https://github.com/k-allard/dining_philosophers/tree/main/roller_coaster) to see the simplest example of semaphore usage

## :star: How philos' processes are launched
philo_three.c: ``main()`` --> ``starting()`` -->  
launch.c: ``launch_philos()`` -->  
philo_life.c: ``philo_entry_function()``
