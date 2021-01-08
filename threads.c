// -------------------------------- IMPORTATIONS --------------------------------

//standard
#include <stdio.h>
#include <stdlib.h>



//multithreading
#include <pthread.h>



//own header
#include "threads.h"




















// -------------------------------- THREADS --------------------------------

//create - delete
thread* thread_create(void* (*function)(void*)){
	if(function == NULL){
		printf("RUNTIME ERROR > threads.c : thread_create() : Thread function is NULL.\n");
		return NULL;
	}

	//create new thread instance
	thread* t = malloc(sizeof(thread));
	if(t == NULL){
		printf("FATAL ERROR > threads.c : thread_create() : Computer refuses to give more memory.\n");
		exit(EXIT_FAILURE);
	}

	//set struct values
	t->function = function;
	t->tid = 0; //t->tid will be set when launching the thread

	return t;
}

void thread_delete(thread* t){

	//error cases
	if(t == NULL){
		printf("RUNTIME ERROR > threads.c : thread_delete() : Thread is NULL.\n");
		return;
	}
	if(t->function == NULL){
		printf("RUNTIME ERROR > threads.c : thread_delete() : Thread function is NULL.\n");
		return;
	}

	//liberating
	free(t->function);
	free(t);
}



//start - stop
void thread_start(thread* t){

	//error cases
	if(t == NULL){
		printf("RUNTIME ERROR > threads.c : thread_start() : Thread is NULL.\n");
		return;
	}
	if(t->function == NULL){
		printf("RUNTIME ERROR > threads.c : thread_start() : Thread function is NULL.\n");
		return;
	}

	//launch thread execution
	pthread_create(
		&(t->tid),
		NULL,
		t->function,
		NULL
	);
}

void thread_stop(thread* t, char waitForEnd){ //waitForEnd should be one of the following constants :
                                              // THREAD__WAIT_FOR_END, THREAD__INTERRUPT
	//error cases
	if(t == NULL){
		printf("RUNTIME ERROR > threads.c : thread_stop() : Thread is NULL.\n");
		return;
	}
	if(t->function == NULL){
		printf("RUNTIME ERROR > threads.c : thread_stop() : Thread function is NULL.\n");
		return;
	}

	//stop thread
	if(waitForEnd){
		if( pthread_join(t->tid, NULL) ){
			printf("RUNTIME ERROR > threads.c : thread_stop() : Thread was not detected as \"active\".\n");
			return;
		}
	}else{
		if( pthread_cancel(t->tid) ){
			printf("RUNTIME ERROR > threads.c : thread_stop() : Thread was not detected as \"active\".\n");
			return;
		}
	}
}
