#include <stdio.h>

int main() {
  int c;
  c = getchar();
  while(c != '\033') {
    putchar(c);
    c = getchar();
  }
  printf("wcisnales ESC");
}
