// ---------------- IMPORTATIONS ----------------

//standard
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



//threads utility
#include "threads.h"




















/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prog [V.V.V] ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                            threads.h demonstration program

        Blablabla about the subject.

    DD/MM/YYYY > [V.V.V] :
    - Added something.
    - Added something else.

    DD/MM/YYYY > [V.V.V] :
    - Added something that wasn't before.
    - Fixed a bug.
    - Added something else.
    - Added something else again.

    BUGS : Active bugs in last version.
    NOTES : Notes.

    Contact : 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




















// ---------------- THREADS ----------------

//functions
void* f1(void* args){

	//count from 0 to -20, each seconds
	for(int i=0; i > -21; i--){
		printf("Thread_1 > %i.\n", i);
		usleep(1000000);
	}

	return NULL;
}

void* f2(void* args){

	//count from 0 to 99, each half seconds
	for(int i=0; i < 100; i++){
		printf("Thread_2 > %i.\n", i);
		usleep(500000);
	}

	return NULL;
}




















// ---------------- EXECUTION ----------------

//main
int main(){
	//presentation
	printf("This is a basic example of multithreading using \"threads.c/.h\".\n");



	//create threads
	thread* t1 = thread_create(f1);
	thread* t2 = thread_create(f2);

	//error cases
	if(t1 == NULL || t2 == NULL){
		printf("FATAL ERROR > prog.c : main() : Cannot create both threads, exiting program.\n");
		exit(EXIT_FAILURE);
	}



	//start thread 1
	printf("I.A. > Starting thread 1.\n");
	thread_start(t1);

	//wait 2.5 seconds
	printf("I.A. > Waiting 2.5 seconds.\n");
	usleep(2500000);

	//start thread 2
	printf("I.A. > Starting thread 2.\n");
	thread_start(t2);

	//wait 10 seconds
	printf("I.A. > Waiting 10 seconds.\n");
	usleep(10000000);



	//stop thread 2
	printf("I.A. > Stopping thread 2 in \"interrupt\" mode.\n");
	thread_stop(t2, THREAD__INTERRUPT);

	//wait 3 second
	printf("I.A. > Waiting 3 second.\n");
	usleep(3000000);

	//stop thread 1
	printf("I.A. > Stopping thread 1 in \"wait for end\" mode.\n");
	thread_stop(t1, THREAD__WAIT_FOR_END);

	//end message
	printf("I.A. > Program terminated.\n");



	return EXIT_SUCCESS;
}
