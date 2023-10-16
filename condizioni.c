#include <stdio.h>

int main() {
    int temp, i;
    int dispari = 1;
    int divisibiliTre = 1;
    int restoSette = 0;
    int numCento = 0;
    int list[10]; // TODO: change size

    do {
        scanf("%d", &temp);
        if (temp != 0) {
            list[i] = temp;
        }
        i++;
    } while (temp != 0);

    for (int i=0; i<sizeof(list) / sizeof(list[0]); i++) {
        // TUTTI DISPARI
        if (list[i] % 2 == 0) {
            dispari = 0;
        }
        // TUTTI MULTIPLI DI 3
        if (list[i] % 3 != 0) {
            divisibiliTre = 0;
        }
        // ESISTE UN NUM DIVISIBILE PER 7
        if (list[i] % 10 == 7) {
            restoSette = 1;
        }
        // ESISTE UN NUM PARI A 100
        if (list[i] == 100) {
            numCento = 1;
        }
    }

    printf("%s", dispari ? "TUTTI DISPARI\n" : "");
    printf("%s", divisibiliTre ? "TUTTI_MULTIPLI_3\n" : "");
    printf("%s", restoSette ? "ESISTE_R7\n" : "");
    printf("%s", numCento ? "ESISTE_100\n" : "");
}