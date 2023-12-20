#include <stdio.h>
#include <stdbool.h>

int e2R(const size_t rows, const size_t cols, const int mat[rows][cols],
        const size_t rags[rows], const int val, size_t i, size_t n) 
{
    bool found = false; 

    if (n+1 != rags[i]) {
        if (mat[i][n] == val) {
            found = true;
        } else {
            e2R(rows, cols, mat, rags, val, i, n+1);
        }
    }

    return found ? rags[i] : -1;
}

int e2(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows], 
       const int val)
{
    
}