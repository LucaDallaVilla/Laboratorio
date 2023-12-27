#include <stdio.h>

void shiftLeft(int a[], int start, int end) {
    if (start < end) {
        a[start] = a[start + 1];
        shiftLeft(a, start + 1, end);
    }
}

void e2R(int a[], size_t *p_aVal, int min, int max, int index) {
    if (index < *p_aVal) {
        if (a[index] < min || a[index] > max) {
            shiftLeft(a, index, *p_aVal - 1);
            (*p_aVal)--;
            e2R(a, p_aVal, min, max, index);
        } else {
            e2R(a, p_aVal, min, max, index + 1);
        }
    }
}

void e2(size_t *p_aVal, int a[], const int min, const int max) {
    e2R(a, p_aVal, min, max, 0);
}

int main() {
    int a[] = {5, 8, 3, 2, 10, 12, 7};
    int aVal = 7;
    int min = 5;
    int max = 10;

    // Stampa l'array originale
    printf("Array originale: ");
    for (int i = 0; i < aVal; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Chiamata alla funzione e2
    e2(a, &aVal, min, max);

    // Stampa l'array modificato
    printf("Array modificato: ");
    for (int i = 0; i < aVal; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Stampa il numero di elementi rimasti nell'array
    printf("Numero di elementi rimasti: %d\n", aVal);

    return 0;
}
