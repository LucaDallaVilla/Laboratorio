#include <stdio.h>

int main() {
    int number1;
    int number2;
    int somma;

    printf("Inserisci il primo numero: ");
    scanf("%d", &number1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &number2);

    somma = number1 + number2;
    printf("La somma vale: %d\n", somma);

    return 0;
}