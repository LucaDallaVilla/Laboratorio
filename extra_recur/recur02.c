#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int e2R(const int a[], const int val, const size_t left, const size_t right) {
    int somma = 0;

    if (left == right-1 || left >= right) {
        if (a[left] >= -val && a[left] <= val) {
            somma += a[left];
            // printf("SOMMA: %d", somma);
        }
    } else {
        size_t mid = left + (right-left) / 2;
        // printf("%ld-%ld, %ld-%ld\n", left, mid, mid, right);
        somma += e2R(a, val, left, mid);
        somma += e2R(a, val, mid, right);
    }

    return somma;
}

int e2(const size_t aLen, const int a[], const int val) {
    return e2R(a, val, 0, aLen);
}