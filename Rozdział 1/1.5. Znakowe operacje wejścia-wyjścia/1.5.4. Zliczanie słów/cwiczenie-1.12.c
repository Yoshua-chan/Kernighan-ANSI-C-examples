#include <stdio.h>

int main() {
  int c;
  int whiteOccured;
  whiteOccured = 0;
  
  c = getchar();
  while(c != EOF) {
      if(c == ' ' || c == '\t' || c == '\n') {
        if(whiteOccured == 0)
          putchar('\n');
        whiteOccured = 1;
      } else {
        putchar(c);
        whiteOccured = 0;
      }
    c = getchar();
    }
  
}
