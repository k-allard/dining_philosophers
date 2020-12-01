## :star: Permitted functions :  
__memset__, malloc, free, write, __usleep__, __gettimeofday__, __pthread_create__, 
__pthread_detach__, __pthread_join__, __pthread_mutex_init__, __pthread_mutex_destroy__, 
__pthread_mutex_lock__, __pthread_mutex_unlock__

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

:round_pushpin:  __pthread_mutex_init__ - creating a new mutex  
:round_pushpin:  __pthread_mutex_lock__ - locking a mutex    
A mutex is initialized and then a lock is achieved by calling the following two functions :  
`int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);`  
`int pthread_mutex_lock(pthread_mutex_t *mutex);`  
Once a thread has locked a piece of code with `mutex` then no other thread can execute the same region of code
until it is unlocked by the thread who locked it.

:round_pushpin:  __pthread_mutex_unlock__ - unlocking a mutex  
:round_pushpin:  __pthread_mutex_destroy__ - destroying a mutex  
`int pthread_mutex_unlock(pthread_mutex_t *mutex);`  
`int pthread_mutex_destroy(pthread_mutex_t *mutex);`  
The first function above `releases the lock` and the second function `destroys the lock` so that it cannot be used anywhere in future.

## :star: Mutex usage pattern

```
#include <pthread.h>

pthread_t tid[2];
pthread_mutex_t lock;

void *func_that_does_smth(void *args)
{
    pthread_mutex_lock(&lock);

   /* Does something */

    pthread_mutex_unlock(&lock);
    return (NULL);
}

int main(void)
{
    int i = 0;
    int err;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        // Mutex init error
        return (1);
    }

    while (i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &func_that_does_smth, NULL);
        if (err)
            // Thread create error
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    pthread_mutex_destroy(&lock);

    return (0);
}
```