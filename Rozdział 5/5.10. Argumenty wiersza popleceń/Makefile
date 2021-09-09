CC=gcc

PROGRAMS=grep echo entab detab expr tail showtabs

all: $(PROGRAMS)

grep: grep.c
	$(CC) grep.c -o ./grep

echo: echo.c
	$(CC) echo.c -o ./echo

entab: entab.c
	$(CC) entab.c -o ./entab

detab: detab.c
	$(CC) detab.c -o ./detab

expr: expr.c
	$(CC) expr.c -o ./expr -lm

tail: tail.c
	$(CC) tail.c -o ./tail

showtabs: showtabs.c
	$(CC) showtabs.c -o ./showtabs

clean:
	rm -f $(PROGRAMS)