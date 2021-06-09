comment: functions.o main.o
	gcc functions.o main.o -o comment

functions.o: functions.c
	gcc -c functions.c

main: main.c
	gcc -c main.o

clean:
	rm *.o comment
