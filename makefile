#executable
run: threads.o prog.o
	gcc -Wall -o run prog.o threads.o -pthread -O2
	rm -f *.o



#example program
prog.o: prog.c threads.h
	gcc -Wall -c prog.c -O2



#threads library
threads.o: threads.c threads.h
	gcc -Wall -c threads.c -O2
