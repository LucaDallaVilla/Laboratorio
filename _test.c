#include <stdio.h>
#include <time.h>
#include <math.h>


int main() {
    clock_t start = clock();

    for (double i=1.0; i<=100000.0; i++) {
        sqrt(i);
    }

    clock_t end = clock();
    printf("TEMPO: %f secondi.\n", (double)(end - start) / CLOCKS_PER_SEC);
}