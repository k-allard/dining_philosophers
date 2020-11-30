__memset__, malloc, free, write, __usleep__, __gettimeofday__, __pthread_create__, 
__pthread_detach__, __pthread_join__, __pthread_mutex_init__, __pthread_mutex_destroy__, 
__pthread_mutex_lock__, __pthread_mutex_unlock__

1. __memset__ - заполнение массива байтов символом  
`void *memset (void *dest, int c, size_t n);`  
`dest` – указатель на заполняемый массив  
`с` – код символа для заполнения  
`n` – размер заполняемой части массива в байтах  

2. __usleep__ – приостановка работы потока  
`int usleep (useconds_t usec);`  
`usec` – время задержки в микросекундах
Возвращаемое значение:  
0 - если истекло время приостановки, указанное в аргументе функции,  
-1 - если приостановка была прервана сигналом  

3. __gettimeofday__ - получение времени с начала эпохи  
`int gettimeofday(struct timeval *tv, struct timezone *tz);`  
struct   `timeval` {  
     long    tv_sec;         // секунды  
     long    tv_usec;        // микросекунды  
};  

4. __pthread_create__ - 
