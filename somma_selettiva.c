#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX_N 20

int main(void) {
    int n;
    // printf("Quanti elementi? ");
    scanf("%d", &n);
    
    if (n>MAX_N) {
        printf("Errore: numero di elementi non valido.\n");
        exit(1);
    } else if (n == 0) {
        printf("Vuoto.");
        exit(1);
    } else if (n < 0) {
        printf("Errore: numero di elementi non valido.\n");
        exit(1);
    }
    
    int seq[n];
    int min = INT_MAX;
    for (int i=0; i<n; i++) {
        // printf("Inerire l'elemento %d.", i);
        scanf("%d", &seq[i]);
        if (seq[i] < min) {
            min = seq[i];
        }
    }
    
    int somma = 0;
    int min_q = pow(min, 2);
    for (int i=0; i<n; i++) {
        if (seq[i] >= min_q) {
            somma += seq[i];
        }
    }
    
    printf("%d", somma);
}