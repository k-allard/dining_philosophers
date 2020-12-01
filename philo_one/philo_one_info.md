## :star: Permitted functions :  
__memset__, malloc, free, write, __usleep__, __gettimeofday__, __pthread_create__, 
__pthread_detach__, __pthread_join__, __pthread_mutex_init__, __pthread_mutex_destroy__, 
__pthread_mutex_lock__, __pthread_mutex_unlock__

:round_pushpin:  __memset__ - заполнение массива байтов символом  
`void *memset (void *dest, int c, size_t n);`  
`dest` – указатель на заполняемый массив  
`с` – код символа для заполнения  
`n` – размер заполняемой части массива в байтах  

:round_pushpin:  __usleep__ – приостановка работы потока (треда)  
`int usleep (useconds_t usec);`  
`usec` – время задержки в микросекундах
Возвращаемое значение:  
0 - если истекло время приостановки, указанное в аргументе функции,  
-1 - если приостановка была прервана сигналом  

:round_pushpin:  __gettimeofday__ - получение времени с начала эпохи  
`int gettimeofday(struct timeval *tv, struct timezone *tz);`  
struct   `timeval` {  
     long    tv_sec;         // секунды  
     long    tv_usec;        // микросекунды  
};  

:round_pushpin:  __pthread_create__ - создание треда  
`int pthread_create(pthread_t *thread, const pthread_attr_t *attr,  
void *(*start_routine)(void *), void *arg);`  
The 1st argument is a pointer to `thread_id` which is set by this function.  
The 2nd argument specifies `attributes`. If the value is NULL, then default attributes shall be used.  
The 3rd argument is `name of function to be executed` for the thread to be created.  
The 4th argument is used to pass `arguments` to the function, myThreadFun.

:round_pushpin:  __pthread_detach__ - отсоединение треда  

:round_pushpin:  __pthread_join__ - ожидание завершения треда  
It blocks the `calling thread` until the `thread with id in 1st argument` terminates.  

:round_pushpin:  __pthread_mutex_init__ - создание нового мьютекса  
:round_pushpin:  __pthread_mutex_lock__ - lock мьютекса    
A mutex is initialized and then a lock is achieved by calling the following two functions :  
`int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);`  
`int pthread_mutex_lock(pthread_mutex_t *mutex);`  
Once a thread has locked a piece of code with `mutex` then no other thread can execute the same region of code
until it is unlocked by the thread who locked it.

:round_pushpin:  __pthread_mutex_unlock__ - unlock мьютекса  
:round_pushpin:  __pthread_mutex_destroy__ - дестрой мьютекса  
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