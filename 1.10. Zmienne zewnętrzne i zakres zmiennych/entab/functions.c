#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

int getln(char* string, int max) {
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

void entab(char* string, int length , int tabWidth) {

  int spaces = 0;

  for(int i = 0; i < length; i++) {
    if(string[i] == ' ') {
      spaces++;
    }
    else {
      for(int k = 0; k < spaces; k++) {
        putchar(' ');
      }
      spaces = 0;
      putchar(string[i]);
    }

    if(spaces == tabWidth){
      putchar('\t');
      spaces = 0;
    }
  }
}
