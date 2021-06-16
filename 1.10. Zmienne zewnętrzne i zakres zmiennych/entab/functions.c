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
char* pinComment(char* string) {
  int i;

  for(i = 0; string[i] != '\n' && string[i] != '\0'; i++){
    if(string[i] == '/' && string[i+1] == '*') {
      string[i] = '\0';
    }
    /*if(string[i] == '/' && string[i-1] == '*') {
      
    }*/
  }
  return NULL;
}
