#include <stdio.h>

float FtoC(float fahr) {
  float cels;
  cels = (5.0/9.0) * (fahr - 32);
  return cels;
}

int main() {
  float fahr;
  int upper, lower, step;
  lower = 0;
  upper = 500;
  step = 10;
  fahr = lower;

  while(fahr <= upper) {
    printf("%3.0f  %6.1f\n", fahr, FtoC(fahr));
    fahr = fahr + step;
  }
}
