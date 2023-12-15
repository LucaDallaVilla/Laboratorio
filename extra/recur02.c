#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int e2R(const int a[], const int val, const size_t left, const size_t right) {
    int somma = 0;

    if (right-left == 1 || left >= right) {
        somma = a[left];
    } else {
        int mid = left + (right-left) / 2;
        somma = e2R(a, val, left, mid);
        somma = e2R(a, val, mid, right);
        int val_neg = -1 * val;
        // printf("%d () %d\n", val_neg, val);
        if (a[left] >= val_neg && a[left] <= val) {
            somma += a[left];
            printf("SOMMA: %d", somma);
        }
    }

    return somma;
}

int e2(const size_t aLen, const int a[], const int val) {
    return e2R(a, val, 0, aLen);
}