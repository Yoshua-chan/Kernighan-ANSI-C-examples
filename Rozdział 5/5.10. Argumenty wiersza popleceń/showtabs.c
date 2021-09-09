#include <stdio.h>

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

int printred(char* str) {
    printf("\e[1;31m");
    printf("%s", str);
    printf("\e[0m");
}

#define MAXLINE 100000

int main() {
    char line[MAXLINE];
    int len;
    char c;

    while((len = getln(line, MAXLINE)) > 0) {
        for(int i = 0; (c = line[i]) != '\0'; i++) {
            if(line[i] == '\t') {
                printred("t");
            }
            else(putchar(line[i]));
        }
    }
}
