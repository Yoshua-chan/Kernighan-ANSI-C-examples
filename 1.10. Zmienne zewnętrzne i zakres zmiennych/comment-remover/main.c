#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

#define MAXLINE 1000
int main() {
  bool inQuotes = false;
  char* newPtr;
  //bool* inq_ptr = &inQuotes;
  char string[30];
  int len;
  while((len = getln(string, MAXLINE)) > 0) {
    newPtr = pinCommentBoundries(string, NULL, NULL); //wywołane przez NULL bo pointery nic na razie nie robią
    printf("%s", string);
    if(newPtr != 0) {
      printf("%s", newPtr);
    }
  }
}
