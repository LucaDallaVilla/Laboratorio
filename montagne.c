#include <stdio.h>

int main() {
    int max = 0;
    char montagnaMax[20];
    int success;
    
    do {
        char montagna[20];
        int altezza;
        success = scanf("%s %d", montagna, &altezza);
        printf("SUCCESS: %d\n", success);

        if (altezza > max) {
            max = altezza;
            for (int i=0; i<20; i++) {
                montagnaMax[i] = montagna[i];
            }
        }

    } while (success == 2);

    printf("La montagna più alta è %s (%d metri).\n", montagnaMax, max);
    return 0;
}