#include <stdio.h>
#define NUM_TAGLI 6

const int tagli_monete[NUM_TAGLI] = {1,2,5,10,20,50};

int main() {
    int prezzo;
    printf("Inserire prezzo: ");
    scanf("%d", &prezzo);

    int cicla = 1;
    while (prezzo != 0) {
        for (int i=NUM_TAGLI; i>=0 && cicla; i--) {
            if (tagli_monete[i] <= prezzo) {
                prezzo -= tagli_monete[i];
                printf("%d ", tagli_monete[i]);
                cicla = 0;
            }
        }
        cicla = 1;
    }
    puts("");
}