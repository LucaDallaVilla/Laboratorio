#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const int k, int *pMaxSum) 
{
    int ret = 0;
    int somma_max = 0;
    int somma = 0;
    
    for (int i=0; i<rows; i++) {
        somma = 0;
        for (int j=0; j<rags[i]; j++) {
            somma += mat[i][j];
        }
        if (somma % k == 0) {
            ret += 1;
            if (somma > somma_max) {
                somma_max = somma;
            }
        }
    }
    
    if (ret > 1) {
        *pMaxSum = somma_max;   
    }
    return ret == rows;
}