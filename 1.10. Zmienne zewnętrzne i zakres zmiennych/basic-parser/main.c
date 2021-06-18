#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

#define MAXLINE 1000
int main() {
  bool comment = false;
  char line[MAXLINE];
  int len = 0;

  while((len = getln(line, MAXLINE)) > 0) {
    transformLine(line, len, &comment);
    println(line, len);
  }
}
