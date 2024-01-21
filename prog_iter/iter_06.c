#include <stdio.h>
#include <stdbool.h>

bool esiste_val_in_arrayR(size_t aLen, const int a[], int val, size_t n) {
    if (n < aLen) {
        if (a[n] == val) {
            return true;
        } else {
            return esiste_val_in_arrayR(aLen, a, val, n+1);
        }
    }

    return false;
}

int e2R(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows], 
       const int val, size_t r) 
{
    size_t somma = 0;

    if (r < rows) {
        if (esiste_val_in_arrayR(rags[r], &mat[r][0], val, 0)) {
            somma += rags[r];
        }
        somma += e2R(rows, cols, mat, rags, val, r+1);
    }

    return somma;
}

int e2(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows], 
       const int val)
{
    return e2R(rows, cols, mat, rags, val, 0);
}