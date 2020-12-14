# :fork_and_knife: Dining philosophers problem
### _with philosophers being distinct processes_  
_and all the forks being in the middle of the table_

## :star: Permitted functions :  
memset, malloc, free, write, __fork__, __kill__, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, __waitpid__, sem_open, sem_close, sem_post, sem_wait, sem_unlink

## :star: Processes

- __fork__ - 
- __kill__ - 
- __waitpid__ - 

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
