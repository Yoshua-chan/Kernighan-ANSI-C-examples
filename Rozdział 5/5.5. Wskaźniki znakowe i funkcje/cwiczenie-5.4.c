#include <stdio.h>
#include <string.h>

int strend1(char* src, char* end) {
    int srcIndex = strlen(src);
    int endIndex = strlen(end);

    if(srcIndex < endIndex) //end can't be inside src if end is longer
        return 0;

    for(; src[srcIndex] == end[endIndex]; srcIndex--, endIndex--)
        if(endIndex == 0)
            return 1;
    return 0;
}


int main() {
    printf("%d\n", strend1("Hello, World!", " World!"));
    printf("%d\n", strend1("Hello, World!", "'sup"));
}