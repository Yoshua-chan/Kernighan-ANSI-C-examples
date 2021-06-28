#include <stdio.h>

int main(){
  int c;
  c = getchar();
  while(c != EOF) {
    printf("%d", (c != EOF));
    c = getchar();
    // jeśli wpiszemy napis to po wykonaniu pętli getchar() nadal będzie czekał
    // na wprowadzenie kolejnego znaku, więc wyrażenie (c != EOF) nigdy nie będzie fałszywe
  }
  printf("%d", (c != EOF));
  // Jeśli wprowadzimy stringa poprzez operator | (pipe), wtedy strumień zakończy się znakiem
  // EOL, więc powyższa linijka wypisze wartość równą 0
}
