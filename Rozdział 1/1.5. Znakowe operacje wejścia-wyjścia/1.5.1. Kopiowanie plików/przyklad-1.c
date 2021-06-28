#include <stdio.h> 

int main() {
  int c;
  c = getchar();
  while(c != EOF) {
    putchar(c); 
    c = getchar();
  }
  // na powyższym przykładzie widać, że jeśli zostanie wprowadzony string dłuższy niż 1 znak
  // wtedy każde wywołanie funkcji getchar() będzie zwracać kolejne znaki tego stringa.
  //
  // Podobnie jest w c++ z std::cin
}
