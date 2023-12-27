#include <stdio.h>
#include <stdbool.h>

int e2R(const size_t rows, const size_t cols,
        const int mat[rows][cols], const size_t rags[rows],
        const int val, int r, int c) 
{
    int somma = 0;

    if (r < rows && c < cols) {
        if (mat[r][c] == val) {
            somma = e2R(rows, cols, mat, rags, val, r+1, 0);
            somma += rags[r];
        } else {
            if (c+1<rags[r]) {
                somma = e2R(rows, cols, mat, rags, val, r, c+1);
            } else {
                somma = e2R(rows, cols, mat, rags, val, r+1, 0);
            }
        }
    }

    return somma;
}

int e2(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows], 
       const int val)
{
    return e2R(rows, cols, mat, rags, val, 0, 0);
}