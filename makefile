#executable
run: threads.o prog.o
	gcc -Wall -o run prog.o threads.o -pthread -O2
	rm -f *.o



#example program
prog.o: src/prog.c lib/threads.h
	gcc -Wall -c src/prog.c -O2



#threads library
threads.o: lib/threads.c lib/threads.h
	gcc -Wall -c lib/threads.c -O2
