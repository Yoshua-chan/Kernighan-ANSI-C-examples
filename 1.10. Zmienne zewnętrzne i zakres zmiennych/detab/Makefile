CC=gcc

detab.out: functions.o main.o
	$(CC) functions.o main.o -o detab.out

functions.o: functions.c
	$(CC) -c functions.c

main: main.c
	$(CC) -c main.o

clean:
	rm *.o detab.out
