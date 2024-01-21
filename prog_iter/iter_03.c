#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int calcola_prodotto(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
        const int c) {
    int prodotto = 1;

    for (int r=0; r<rows; r++) {
        if (rags[r] > c) {
            prodotto *= mat[r][c];
        }
    }

    return prodotto;
}

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    int *pMinSumProd) 
{
    int selected_rows = 0;
    int prodotto = 1;
    int somma = 0;
    int somma_min = INT_MAX;

    for (int r=0; r<rows; r++) {
        somma = 0;
        for (int c=0; c<rags[r]; c++) {
            prodotto = 0;
            if (mat[r][c] % 3 == 0) {
                prodotto = calcola_prodotto(rows, cols, mat, rags, c);
                // printf("Prodotto della colonna %d: %d\n", c, prodotto);
                somma += prodotto;
            }
        }
        // printf("Somma della riga %d: %d\n", r, somma);
        if (somma != 0 && somma % 10 == 0) {
            selected_rows++;
            if (somma < somma_min) {
                somma_min = somma;
            }
        }
    }

    // printf("Selected rows: %d\n", selected_rows);
    if (selected_rows >= 2) {
        *pMinSumProd = somma_min;
    }
    
    return selected_rows >= 2;
}