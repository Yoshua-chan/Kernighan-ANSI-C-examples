#include <stdio.h>

int main() {
  int c = 0, tabs = 0, nl = 0;
  int chars[94];

  for(int i = 0; i < 94; i++)
    chars[i] = 0;

  c = getchar();
  while(c != EOF) {
    if(c == '\t') {
      tabs++;
    }
    else if(c == '\n') {
      nl++;
    }
    else if(c >= ' ' && c <= 125) {
      ++chars[c - ' '];
    }
    c = getchar();
  }
  printf("\\t |");
  for(int i = 0; i < tabs; i++) {
    putchar('-');
  }
  putchar('\n');

  printf("\\n |");
  for(int i = 0; i < nl; i++) {
    putchar('-');
  }
  putchar('\n');

  for(int k = 0; k < 94; k++) {
    if(k == 0) {
      printf("\\  |");
    } else {
      printf("%c  |", k + 32);
    }
    for(int i = 0; i < chars[k]; i++) {
      putchar('-');
    }
    putchar('\n');
  }
}
