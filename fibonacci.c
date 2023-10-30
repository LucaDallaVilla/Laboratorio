#include <stdio.h>

int main() {
    int n;
    printf("Fino a che numero? ");
    scanf("%d", &n);
    int sol[n];
    sol[0] = 0;
    sol[1] = 1;

    // somma i due elementi precedenti della sequenza (inizia da 0-1)
    for (int i=2; i<=n; i++) {
        sol[i] = sol[i-1] + sol[i-2];
    }

    // stampa a schermo la sequenza
    for (int i=0; i<n; i++) {
        printf("%d\n", sol[i]);
    }
}