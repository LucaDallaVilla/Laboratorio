#include <stdio.h>
#include <stdbool.h>


bool aggiungi_elementi(const size_t rows, const size_t cols,
                        int mat[rows][cols],
                        size_t rags[rows], size_t row)
{
    bool ret = false;

    // per ogni elemento della riga row...
    for (size_t c = 0; c < rags[row]; c++)
    {
        // controlla se esiste un elemento positivo divisibile per 3
        if (mat[row][c] > 0 && mat[row][c] % 3 == 0) 
        {
            // assicurati che ci sia ancora spazio in fonda alla riga corrente
            if (rags[row] < cols)
            {
                int elemento = mat[row][c];
                if (elemento > 0 && elemento % 3 == 0) 
                {
                    size_t col = rags[row];
                    mat[row][col] = elemento / 3;
                    rags[row]++;
                    ret = true;
                }
            }
        }
    }

    return ret;
}


/* void copia_matrice(const size_t rows, const size_t cols,
                   int mat1[rows][cols], size_t rags[rows],
                   int mat2[rows][cols], size_t rags2[rows])
{
    for (size_t r = 0; r < rows; r++)
    {
        for (size_t c = 0; c < rags[r]; c++)
        {
            mat2[r][c] = mat1[r][c];
        }
    }
} */

bool e1(const size_t rows, const size_t cols,
        int mat[rows][cols], size_t rags[rows])
{
    /* int mat2[rows][cols];
    size_t rags2[rows]; */
    int counter = 0;
    // copia_matrice(rows, cols, mat1, rags, mat2, rags2);

    for (size_t r = 0; r < rows; r++)
    {
        counter += aggiungi_elementi(rows, cols, mat, rags, r);
    }

    return counter == rows;
}