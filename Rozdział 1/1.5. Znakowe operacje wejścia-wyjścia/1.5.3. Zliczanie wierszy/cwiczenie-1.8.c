#include <stdio.h>

int main() {
  long int tab = 0;
  long int spc = 0;
  long int nl = 0;
  int c;
  c = getchar();
  while(c != EOF) {
    if(c == '\t') {
      tab++;
    } else if(c == 32){
      spc++;
    } else if(c == '\n'){
      nl++;
    } else;
    c = getchar();
  }
  printf("Taby: %ld\nSpacje: %ld\nZnaki konca linii: %ld\n", tab, spc, nl);
}
