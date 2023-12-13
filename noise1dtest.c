#include <stdio.h>
#include <stdlib.h>
#include "noise1d.c"

int main() {

    int size = 100;
    
    for (int i=0; i<size; i++) {
        double arg = (double)i / 10.0;
        printf("%f\t%f\n", arg, noise(arg));
    }
    
    return 0;
    
}