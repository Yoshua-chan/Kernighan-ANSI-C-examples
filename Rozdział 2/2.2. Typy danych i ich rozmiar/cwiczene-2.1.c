/* 
2.2. Typy danych i ich rozmiar

Ćwiczenie 2.1.
Napisz program, który bada zakresy wartości zmeinnych char, short, int i long ze znakiem i bez znak,
poprzez wypisywanie wartości ze standardowych nagłówków oraz przez obliczenie rozmiarów.
Zadanie trudniejsze przy obliczeniach: określ zakresy typów zmiennoprzecinkowych
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>



int main() {
  printf("Headery:\n");

  printf("Unsigned char: 0 - %d\n", UCHAR_MAX);
  printf("Signed char: %d - %d\n", SCHAR_MIN, SCHAR_MAX);
  
  printf("Unsigned short: 0 - %d\n", USHRT_MAX);
  printf("Signed short: %d - %d\n", SHRT_MIN, SHRT_MAX);

  printf("Unsigned int: 0 - %u\n", UINT_MAX);
  printf("Signed int: %d - %d\n", INT_MIN, INT_MAX);

  printf("Unsigned long: 0 - %lu\n", ULONG_MAX);
  printf("Signed long: %ld - %ld\n", LONG_MIN, LONG_MAX);

  printf("\nObliczeniowo:\n");

  printf("Unsigned char: 0 - %.0f\n", pow(2, 8) - 1);
  printf("Signed char: %.0f - %.0f\n", -pow(2,7), pow(2,7) - 1);

  printf("Unsigned short: 0 - %.0f\n", pow(2, 16) - 1);
  printf("Signed short: %.0f - %.0f\n", -pow(2,15), pow(2,15) - 1);

  printf("Unsigned int: 0 - %.0f\n", pow(2, 32) - 1 );
  printf("Signed int: %.0f - %.0f\n", -pow(2, 31), pow(2, 31) - 1); 

  printf("Unsigned long: 0 - %lu\n", 0b1111111111111111111111111111111111111111111111111111111111111111);
  printf("Signed long: %.0f - %.0ld\n", -pow(2, 63), ((unsigned long int)pow(2,63)) - 1);

  int x = 0x7f7fffff;
  float y = 0x7f7fffff;

  printf("float: %f", y);
  printf("\nint to float pointer: %f", *(float*)&x);
}
