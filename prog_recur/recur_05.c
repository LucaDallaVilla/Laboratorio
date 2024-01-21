#include <stdio.h>
#include <stdbool.h>

// ritorna true se un elemento val esiste in un dato array
bool esiste_elemento(size_t aLen, int a[], int val, int* i, size_t n) {
    if (n < aLen) {
        if (a[n] == val) {
            *i = n;
            return true;
        } else {
            return esiste_elemento(aLen, a, val, i, n+1);
        }
    }

    return false;
}

// rimuove tutte le occorrenze di un elemento val in un array, 
// partendo da un indice i data in input.
void rimuovi_elementiR(size_t* aLen, int a[], int val, size_t c, size_t n) {
    if (n < *aLen) {
        if (a[n] != val) {
            a[c] = a[n];
            c++;
        }
        rimuovi_elementiR(aLen, a, val, c, n+1);
    } else {
        *aLen = c;
    }
}

int e2R(size_t* p_aLen, int a[], const size_t bLen, const int b[], size_t n) {
    int indexFound = -1;
    if (n < bLen) {
        if (esiste_elemento(*p_aLen, a, b[n], &indexFound, 0)) {
            rimuovi_elementiR(p_aLen, a, b[n], indexFound+1, indexFound+1);
        }
        e2R(p_aLen, a, bLen, b, n+1);
    }

    return (int)*p_aLen;
}

int e2(size_t* p_aLen, int a[], const size_t bLen, const int b[]) {
    return e2R(p_aLen, a, bLen, b, 0);
}