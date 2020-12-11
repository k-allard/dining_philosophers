# Philo_one
### _Dining philosophers problem with threads and semaphore_
## :star: Permitted functions :  
__memset__, malloc, free, write, __usleep__, __gettimeofday__, __pthread_create__, 
__pthread_detach__, __pthread_join__, __sem_open__, __sem_close__, __sem_post__, __sem_wait__, __sem_unlink__

:round_pushpin:  __memset__ - filling a byte string with a byte value  
`void *memset (void *dest, int c, size_t n);`  
`dest` – pointer to a byte string to be filled  
`с` – character code  
`n` – number of bytes to be filled

:round_pushpin:  __usleep__ – suspending a thread  
`int usleep (useconds_t usec);`  
`usec` – delay time in microseconds  
Returns:  
`0` - if the pause time specified in the function argument has expired,  
`-1` - if the pause was interrupted by a signal  

:round_pushpin:  __gettimeofday__ - getting time from the beginning of an epoch  
`int gettimeofday(struct timeval *tv, struct timezone *tz);`  
struct   `timeval` {  
     long    tv_sec;         // secs  
     long    tv_usec;        // microsecs   
};  
This means that `tv_sec` seconds have passed and THEN `tv_usec` microseconds.

:round_pushpin:  __pthread_create__ - creating a thread  
`int pthread_create(pthread_t *thread, const pthread_attr_t *attr,  
void *(*start_routine)(void *), void *arg);`  
The 1st argument is a pointer to `thread_id` which is set by this function.  
The 2nd argument specifies `attributes`. If the value is NULL, then default attributes shall be used.  
The 3rd argument is `name of function to be executed` for the thread to be created.  
The 4th argument is used to pass `arguments` to the function, myThreadFun.

:round_pushpin:  __pthread_detach__ - detaching a thread  

:round_pushpin:  __pthread_join__ - waiting for the thread to terminate  
It blocks the `calling thread` until the `thread with id in 1st argument` terminates.  

## :star: Semaphores

:round_pushpin:  __sem_open__ - initializes and open a named semaphore

:round_pushpin:  __sem_close__ - closes a named semaphore

:round_pushpin:  __sem_post__ - unlocks a semaphore == the value of the semaphore is incremented

:round_pushpin:  __sem_wait__ - locks a semaphore

:round_pushpin:  __sem_unlink__ - remove a named semaphore

### Semaphore usage pattern

```
#include <semaphore.h>



void *func_that_does_smth(void *args)
{

   /* Does something */

    return (NULL);
}

int main(void)
{
    sem_t *sem_id;

}
```
