#include <stdio.h>
#include <stdbool.h>

int e2R(const size_t aLen, const int a[], const size_t bLen, const int b[], int maxLen, int n) {
    int somma = 0;

    if (n == maxLen) {
        somma = 0;
    } else {
        if (n < aLen && n < bLen) {
            somma += a[n] * b[n];
        } else if (n < aLen) {
            somma += a[n] * a[n];
        } else if (n < bLen) {
            somma += b[n] * b[n];
        }
        somma += e2R(aLen, a, bLen, b, maxLen, n+1);
    }

    return somma;
}

int e2(const size_t aLen, const int a[], const size_t bLen, const int b[]) {
    int maxLen = aLen>bLen ? aLen : bLen;
    return e2R(aLen, a, bLen, b, maxLen, 0);
}