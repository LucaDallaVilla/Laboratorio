#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <gmp.h>

int fattoriale_inverso(unsigned long long int m, unsigned long long int* accumulatore);

int main() {
    unsigned long long int m;
    printf("Inserisci il numero m tale che n! = m: ");
    scanf("%llu", &m);

    unsigned long long int accumulatore = 1;
    int n = fattoriale_inverso(m, &accumulatore);
    puts("");
    printf("%llu è il fattoriale di %d.\n", accumulatore, n);
        
    return 0;
}

int fattoriale_inverso(unsigned long long int m, unsigned long long int* accumulatore) {
    int contatore = 0;

    while (*accumulatore <= m) {
        if (*accumulatore >= ULLONG_MAX/2) {
            contatore++;
            break;
        } else {
            *accumulatore *= contatore + 1;
            if (*accumulatore >= m) {
                *accumulatore /= contatore + 1;
                contatore++;    
                break;
            }
        }
        usleep(100000);
        printf("%llu\n", *accumulatore);
        // fflush(stdout);
    }

    return contatore-1;
}

//  18446744073709551615