// Da Wikipedia Italia. https://it.wikipedia.org/wiki/Morra_cinese 

#include <stdio.h>

void isWinning(int *sheldon, int *leonard) {
    int v1 = *sheldon+1;
    int v2 = *sheldon+3;

    if (v1 > 5) {
        v1 = v1 - 5;
    } if (v2 > 5) {
        v2 = v2 - 5;
    }
    
    // Il primo giocatore vince se il secondo giocatore sceglie un'opzione distnte
    // di 1 o di 3 in avanti (caso v1 e v2 rispettivamente)
    if (*leonard == v1 || *leonard == v2) {
        printf("Sheldon");
    } else {
        printf("Leonard");
    }
}

int main() {
    int sheldon, leonard;
    // printf("Inserire due numeri interi compresi tra 1 e 5 inclusi: ");
    int success = scanf("%d %d", &sheldon, &leonard);
    if (success != 2) {
        printf("Non valido");
        return 1;
    } else if (sheldon > 5 || sheldon <= 0 || leonard > 5 || leonard <= 0) {
        printf("Non valido");
        return 1;
    } else if (sheldon == leonard) {
        printf("Pareggio");
    } else {
        isWinning(&sheldon, &leonard);
    }
    
    return 0;
}