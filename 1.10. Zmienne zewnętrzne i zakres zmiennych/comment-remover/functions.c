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

void transformLine(char* line, int length, bool* ptr_comment) {
  for(int i = 0; i < length; i++) {
    if(*ptr_comment == false && line[i] == '/')  {
        if(line[i+1] == '*') {
          *ptr_comment = true;
        }
        else if(line[i+1] == '/') {
          for(; i < length && line[i] != '\n'; i++)
            line[i] = '\0';
          return;
        }
    } else if(*ptr_comment == true && line[i] == '*' && line[i+1] == '/') {
        *ptr_comment = false;
        line[i] = '\0';
        line[i+1] = '\0';
    }
    if(*ptr_comment == true)
        line[i] = '\0';
  }
}

void println(char* line, int length) {
  for(int i = 0; i < length; i++) {
    putchar(line[i]);
  }
}
