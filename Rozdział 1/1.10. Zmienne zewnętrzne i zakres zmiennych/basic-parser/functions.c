#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

int getln(char* string, int max) { //zapisuje wiersz do znaka \n z wejścia standardowego do podanej tablicy
  int i, c;
  for(i = 0; (c = getchar()) != EOF && i < max - 1 && c != '\n' ; i++) {
    string[i] = c;
  }
  if(c == '\n') {
    string[i] = c;
    i++;
  }
  string[i] = '\0';
  return i;
}

void transformLine(char* line, int length, bool* ptr_comment) { //funkcja zastępuje każdy znak w komentarzach NULLem
  for(int i = 0; i < length; i++) {

    if(*ptr_comment == false && line[i] == '/')  {

        if(line[i+1] == '*') { //wykrywa początek komentarza blokowego
          *ptr_comment = true;
        }

        else if(line[i+1] == '/') { //nadpisuje komendarze z dwoma slashami do końca linii z wyłączeniem \n, a następnie kończy funkcje
          for(; i < length && line[i] != '\n'; i++)
            line[i] = '\0';
          return;
        }

    } else if(*ptr_comment == true && line[i] == '*' && line[i+1] == '/') { //wykwywa koniec komentarza blokowego
        *ptr_comment = false;
        line[i] = '\0';
        line[i+1] = '\0';
    }

    if(*ptr_comment == true) //nadpisuje znak nullem, jeśli ten jest wewnątrz komentarza
        line[i] = '\0';
  }

}

void println(char* line, int length) { //printuje cały char o podanej długości, nie kończy się na nullu
  for(int i = 0; i < length; i++) {
    putchar(line[i]);
  }
}
