#include <stdio.h>
#include <stdlib.h>
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

void detab(char* line, int length, int tabWidth) {
  for(int i = 0; i < length; i++) {
    if(line[i] == '\t')
      for(int k = 0; k < tabWidth; k++)
        putchar(' ');
    else
      putchar(line[i]);
  }
}
