#include <stdio.h>

#define ON 1
#define OFF 0

int main() {
  int c, nc, nl, nw;
  nc = nw = nl = 0;
  int state;
  state = OFF;
  
  c = getchar();
  while(c != EOF) {
    ++nc;
    if(c == '\t' || c == ' ' || c == '\n') {
      if(c == '\n') nl++;
      state = OFF;
    }  else if(state == OFF) {
      nw++;
      state = ON;
    }
    c = getchar();
  }
  printf("words:%d, lines:%d, chars:%d", nw, nl, nc);
}
