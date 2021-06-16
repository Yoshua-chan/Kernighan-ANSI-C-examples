CC=gcc
comment.out: functions.o main.o
	$(CC) functions.o main.o -o comment.out

functions.o: functions.c
	$(CC) -c functions.c

main: main.c
	$(CC) -c main.o
	
debug: functions.o main.o
	$(CC) -g functions.o main.o -o debug.out

clean:
	rm *.o *.out
