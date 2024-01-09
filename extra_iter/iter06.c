/* Scrivere un funzione iterativa e1 con le seguenti caratteristiche:

e1 riceve in input una matrice rettangolare (rows, cols, mat[rows][cols]) di interi.
e1 stampa in output tutte le coppie (i,j) che rappresentano l'indice di un punto di sella.
Chiamiamo 'punto di sella' un elemento nella matrice mat[i][j] alla posizione (i,j) che ha le seguenti caratteristiche:
l'elemento mat[i][j] è il massimo nella riga i e minimo nella colonna j.
e1 restituisce true se ogni riga ha almeno un punto di sella, false in tutti gli altri casi.
NOTA: (i1, j1) deve essere stampata prima della coppia (i2, j2) se i1<i2 oppure se (i1==i2 && j1<j2). */

#include <stdio.h>
#include <stdbool.h>


bool is_punto_sella(const size_t rows, const size_t cols,
                    const int mat[rows][cols], size_t row, size_t col)
{
    bool ret = true;

    for (int r=0; r<rows; r++)
    {
        if (mat[r][col] < mat[row][col])
        {
            ret = false;
        }
    }

    for (int c=0; c<cols; c++)
    {
        if (mat[row][c] > mat[row][col])
        {
            ret = false;
        }
    }

    return ret;
}

bool e1(const size_t rows, const size_t cols, const int mat[rows][cols])
{
    size_t counter = 0;
    bool ret = true;

    for (size_t r=0; r<rows; r++)
    {
        for (size_t c=0; c<cols; c++)
        {
            if (is_punto_sella(rows, cols, mat, r, c))
            {
                counter++;
                printf("%ld %ld\n", r, c);
            }
        }

        if (counter <= 0)
        {
            ret = false;
        }
        counter = 0;
    }

    return ret;
}