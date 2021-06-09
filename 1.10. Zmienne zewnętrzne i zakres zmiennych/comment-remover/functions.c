#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

int getln(char* string, int max) {
  int i, c;
  for(i = 0; (c = getchar()) != EOF && i < max - 1 && c != '\n' ; i++) {
    string[i] = c;
  }
  if(c == '\n') {
    string[i] = c;
    i++;
  }
  string[i] = '\0';
  return i;
}

char* pinCommentBoundries(char* string, int* inComment, int* inQotes) {

  /* funkcja zapisuje wartość NULL dla indeksu w którym zaczyna się komentarz w tablicy "string" */
  /* jeśli funkcja zwraca 0, to znaczy, że w linijce podanej w argumencie nie znajduje się koniec komentarza */

  int i;
  int commentStartIndex = 0;
  char* newStartPtr = 0;
  
  for(i = 0; string[i] != '\n'; i++) {
    if(string[i] == '/' && string[i+1] == '*') {
      string[i] = '\0';
    }
    if(string[i] == '/' && string[i-1] == '*') {
      newStartPtr = string + i + 1;
    }
  }
  return newStartPtr;
}
