//Sprawdźmy, czy kilka getcharów następujących po sobie będzie kolejkowany 
#include <stdio.h>

int main() {
  char c;
  c = getchar();

  for(int i = 0; i < 10; i++) {
    putchar(c);
    getchar();
  }
}
