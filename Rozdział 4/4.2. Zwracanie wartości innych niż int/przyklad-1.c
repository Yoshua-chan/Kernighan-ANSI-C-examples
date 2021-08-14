#include <stdio.h>

double atof(char arr[]) {
    double val, power;
    int i, sign;

    for(i = 0; isspace(arr[i]); i++) /*pomija białe znaki*/
        ;
    sign = (arr[i] == '-') ? -1 : 1;
    if(arr[i] == '+' || arr[i] == '-')
        i++; //pomija jeśli plus lub minus, dla minusa uprzednio zmieniając znak na ujemny

    for(val = 0.0; isdigit(arr[i]); i++)
        val = 10.0 * val + (arr[i] - '0');
        
    if(arr[i] == '.')
        i++; //pomija znak kropki;

    for(power = 1.0; isdigit(arr[i]); i++) {
       val = 10.0 * val + (arr[i] - '0'); //liczy tak jakby nie bylo kropki
       power *= 10; //liczy miejsca po przecinku
    }

    return sign * val / power; //kompensuje za wszystkie miejsca po przecinku
    
}
int main(int argc, char* argv[]) {
   printf("%lf", atof(argv[1]));
   return 0;
}