#ifndef THREADS_H
#define THREADS_H




















// -------------------------------- DEFINITIONS --------------------------------

//debug
#define THREAD_DEBUG_ON   //uncomment to enable debug messages



//threads
#define THREAD__WAIT_FOR_END 1
#define THREAD__INTERRUPT 0

struct THREAD{
	void* (*function)(void*);
	pthread_t tid;
};
typedef struct THREAD thread;




















// -------------------------------- THREADS --------------------------------

//create - delete
thread* thread_create(void* (*function)(void*));
void thread_delete(thread* t);

//start - stop
void thread_start(thread* t);
void thread_stop(thread* t, char waitForEnd);




















#endif
