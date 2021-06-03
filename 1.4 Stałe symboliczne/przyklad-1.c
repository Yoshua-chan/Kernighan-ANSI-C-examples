#include <stdio.h>

/* Stałe zdefiniowane przez dyrektywę #define nie są przechowywane w pamięci jako zmienne */
/* Są one zamieniane na odpowiadające im ciągi znaków w momencie kompilacji */

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
  int fahr; 

  for(fahr = LOWER; fahr <= UPPER; fahr += STEP){ 
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
  }
  return 0;
}
