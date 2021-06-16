CC=gcc
entab.out: functions.o main.o
	$(CC) functions.o main.o -o entab.out

functions.o: functions.c
	$(CC) -c functions.c

main: main.c
	$(CC) -c main.o

clean:
	rm *.o entab.out
