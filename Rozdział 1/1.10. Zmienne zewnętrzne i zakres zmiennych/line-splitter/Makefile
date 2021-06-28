CC=gcc
split.out: functions.o main.o
	$(CC) functions.o main.o -o split.out

functions.o: functions.c
	$(CC) -c functions.c

main: main.c
	$(CC) -c main.o

clean:
	rm *.o split.out
