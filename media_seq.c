#include <stdio.h>

int main() {
    int cond = 1;
    int somma = 0;
    int i = 0;
    int temp = 1;

    while (cond) {
        printf("Inserisci un numero: ");
        scanf("%d", &temp);

        if (temp == 0) {
            cond = 0;
        } else if (temp != 0) {
            i++;
            somma += temp;
        }
    }

    printf("%d\n", somma/(i-1));
}