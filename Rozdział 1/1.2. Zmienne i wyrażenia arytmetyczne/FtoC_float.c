#include <stdio.h>

int main() {
  float fahr, cels;
  int upper, lower, step;
  lower = 0;
  upper = 500;
  step = 10;
  fahr = lower;

  while(fahr <= upper) {
    cels = (5.0/9.0)*(fahr-32); // ".0" oznacza, że wyrażenie jest floatem
    printf("%3.0f  %6.1f\n", fahr, cels);
    fahr = fahr + step;
  }
}
