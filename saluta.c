#include <stdio.h>

int main() {
    int hour, minutes;
    
    printf("Inserire l'ora (usare ':' come divisione tra ora e minuti) ");
    scanf("%d:%d", &hour, &minutes);
    printf("%d, %d", hour, minutes);

    if (hour < 6) {
        printf("E' notte.\n");
    } else if (hour < 12) {
        printf("E' mattina\n");
    } else if (hour < 18) {
        printf("E' pomeriggio\n");
    } else if (hour < 24) {
        printf("E' sera\n");
    } else {
        printf("Inserimento non corretto.\n");
    }
}