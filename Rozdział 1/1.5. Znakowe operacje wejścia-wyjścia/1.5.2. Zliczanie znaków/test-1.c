/* Test innego sposobu zliczania znaków przy pomocy dodatkowej funkcji i wskaźników */

#include <stdio.h>

void zlicz(double* ptr) { 
  /* funcja zlicz przyjmuje wskaźnik na doubla i podczas zliczania znaków
     sekswencyjnie zwiększa wartość pod adresem */
  for(*ptr = 0; getchar() != EOF; ++*ptr);
}

int main() {
  double nc;
  zlicz(&nc); /*adres zmiennej nc jest przekazywany do funkcji zlicz,
                więc ulega ona modyfikacji do późniejszego wykorzystania
                w printf  */
  printf("%.0f\n", nc);
}
