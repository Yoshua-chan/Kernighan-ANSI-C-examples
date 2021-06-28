#include <stdio.h>
#include <stdlib.h> //atoi
#include <stdbool.h>
#include <string.h> //strcmp
#include "functions.h"

int main(int argc, char** argv) {

  int tabWidth;

  for(int i = 0; i < argc; i++)
    if(!strcmp(argv[i], "-t"))
      tabWidth = atoi(argv[i+1]);

  const int maxline = 1000;
  char line[maxline];
  int len = 0;

  while( (len = getln(line, maxline)) > 0) {
    detab(line, len, tabWidth);
  }
}
