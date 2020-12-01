Permitted functions :  
__memset__, malloc, free, write, __usleep__, __gettimeofday__, __pthread_create__, 
__pthread_detach__, __pthread_join__, __pthread_mutex_init__, __pthread_mutex_destroy__, 
__pthread_mutex_lock__, __pthread_mutex_unlock__

:round_pushpin: 1. __memset__ - заполнение массива байтов символом  
`void *memset (void *dest, int c, size_t n);`  
`dest` – указатель на заполняемый массив  
`с` – код символа для заполнения  
`n` – размер заполняемой части массива в байтах  

:round_pushpin: 2. __usleep__ – приостановка работы потока (треда)  
`int usleep (useconds_t usec);`  
`usec` – время задержки в микросекундах
Возвращаемое значение:  
0 - если истекло время приостановки, указанное в аргументе функции,  
-1 - если приостановка была прервана сигналом  

:round_pushpin: 3. __gettimeofday__ - получение времени с начала эпохи  
`int gettimeofday(struct timeval *tv, struct timezone *tz);`  
struct   `timeval` {  
     long    tv_sec;         // секунды  
     long    tv_usec;        // микросекунды  
};  

:round_pushpin: 4. __pthread_create__ - создание треда  
`int pthread_create(pthread_t *thread, const pthread_attr_t *attr,  
void *(*start_routine)(void *), void *arg);`  
The 1st argument is a pointer to `thread_id` which is set by this function.  
The 2nd argument specifies `attributes`. If the value is NULL, then default attributes shall be used.  
The 3rd argument is `name of function to be executed` for the thread to be created.  
The 4th argument is used to pass `arguments` to the function, myThreadFun.

:round_pushpin: 5. __pthread_detach__ - отсоединение треда  

:round_pushpin: 6. __pthread_join__ - ожидание завершения треда  
It blocks the `calling thread` until the `thread with id in 1st argument` terminates.  

:round_pushpin: 7. __pthread_mutex_init__ - создание нового мьютекса  

:round_pushpin: 8. __pthread_mutex_destroy__ - дестрой мьютекса  

:round_pushpin: 9. __pthread_mutex_lock__ - lock мьютекса  

:round_pushpin: 10. __pthread_mutex_unlock__ - unlock мьютекса  
