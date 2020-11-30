memset, malloc, free, write, usleep, gettimeofday, pthread_create, 
pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, 
pthread_mutex_lock, pthread_mutex_unlock

1. void *__memset__ (void *destination, int c, size_t n);
destination – указатель на заполняемый массив
с – код символа для заполнения
n – размер заполняемой части массива в байтах

6. usleep – приостановка работы потока
int usleep (useconds_t usec);
useconds_t usec – время задержки в микросекундах
Возвращаемое значение:
0 - если истекло время приостановки, указанное в аргументе функции,
-1 - если приостановка была прервана сигналом

6. gettimeofday 