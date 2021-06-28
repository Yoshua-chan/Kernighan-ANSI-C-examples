#include <stdio.h>

int main () {
  double nc; 

  for(nc = 0; getchar() != EOF; ++nc); /* średnik na końcu
                                          oznacza koniec pierwszej instrukcji
                                          więc pętla for nie ma ciała
                                          printf wykona się poza pętlą */

  printf("%.0f\n", nc); /* "%.0f" oznacza, poziom precyzji bez miejsc
                           po przecinku */


}
