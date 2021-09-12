#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //atoi
#include <string.h> //strcmp

int getln(char* string, int max);
void detab(char* line, int length, int tabWidth);

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

int main(int argc, char** argv) {

  int tabWidth;

  for(int i = 0; i < argc; i++)
    if(!strcmp(argv[i], "-t"))
      tabWidth = atoi(argv[i+1]);

  const int maxline = 100000;
  char line[maxline];
  int len = 0;

  tabWidth = tabWidth == 0 ? 4 : tabWidth;
  while( (len = getln(line, maxline)) > 0) {
    detab(line, len, tabWidth);
  }
}
