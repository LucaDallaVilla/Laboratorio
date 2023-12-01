#include <stdio.h>
#include <limits.h>
#include <time.h>

unsigned long long int fattoriale(int n);

void main () {
    int n;
    printf("Calcolo del fattoriale di: ");
    scanf("%d", &n);
    unsigned long long int calc = fattoriale(n);
    printf("%d! = %llu\n", n, calc);
}

unsigned long long int fattoriale(int n) {
    unsigned long long int ret = 1;

    if (n==0) { 
        ret = 1;
    } else {
        ret = n * fattoriale(n-1);
    }

    return ret;
}