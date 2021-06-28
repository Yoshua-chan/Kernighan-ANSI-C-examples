#include <stdio.h>
#include <stdbool.h>

int getln(char* string, int max);
void transformLine(char* line, int length, bool* ptr_comment);
void println(char* line, int length);

struct Characters {
  int apostrophes;
  int parenthases;
  int braces;
  int brackets;
  int quotes;
};
