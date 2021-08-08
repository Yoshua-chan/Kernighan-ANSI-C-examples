#include <stdio.h>

void escape(char* inString, char* outString) {

  int inIndex = 0, outIndex = 0;

  while(inString[inIndex] != '\0') {
    switch(inString[inIndex]) {
      case '\t':
        outString[outIndex++] = '\\';
        outString[outIndex] = 't';
        outIndex++;
        inIndex++;
      break;
      case '\n':
        outString[outIndex++] = '\\';
        outString[outIndex] = 'n';
        outIndex++;
        inIndex++;
      break;
      case '\\':
        outString[outIndex++] = '\\';
        outString[outIndex] = '\\';
        outIndex++;
        inIndex++;
      break;
      default:
        outString[outIndex] = inString[inIndex];
        outIndex++;
        inIndex++;
      break;
    }
  }
  outString[outIndex] = '\0';
}

int main() {
  char in[500] = "rzujmi\tgumi\npumi\\rzujmi", out[500];
  printf("%s", in);
  escape(in, out);
  printf("\n\n%s", out);
}
