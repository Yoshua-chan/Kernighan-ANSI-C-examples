#include <stdio.h>

int main() {
  int c = 0;
  unsigned int didSpaceOccur = 0;
  c = getchar();
  while(c != EOF) {
    if(c == 32 /*space*/ && didSpaceOccur == 0) {
      putchar(c);
      didSpaceOccur = 1;
    } else if(c == 32 && didSpaceOccur == 1) { 
      ;
    } else {
      didSpaceOccur = 0;
      putchar(c);
    }
    c = getchar();
  }
}
