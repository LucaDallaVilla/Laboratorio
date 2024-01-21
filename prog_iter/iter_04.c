#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) 
{
    bool eseguiCicloC = true;
    bool ret = false;
    int somma = 0;
    size_t sommaTot = 0;

    for (size_t r=0; r<rows; r++) {
        somma = 0;
        eseguiCicloC = true;

        for (size_t c=0; c<rags[r] && eseguiCicloC; c++) {
            if (c < aLen) {
                somma += mat[r][c] * a[c];
            } else {
                eseguiCicloC = false;
            }
        }

        if (somma > 0 && somma % 5 == 0) {
            // printf("sommaTot += %ld (%ld)\n", somma, sommaTot);
            sommaTot += somma;
            ret = true;
        }
    }
    
    if (ret) {
        *pSum = sommaTot;
    }

    return ret;
}