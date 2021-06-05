#include <stdio.h>

/* Zliczanie  znaków srumienia wejściowego */

int main(void) {
  long nc;

  nc = 0;

  while(getchar() != EOF) {
    ++nc; /* Kernighan mówi ażeby zostać na razie przy wersji prefiksowej
             W rozdziale drugim jest to wyjaśnione */
  }
  printf("%ld\n", nc); // "%ld" jest argumentem printf dla long intów
}
