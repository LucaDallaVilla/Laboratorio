/* Scrivere un metodo iterativo e1 con le seguenti caratteristiche:

e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, un intero k, ed un puntatore ad interi pMaxSum
e1 considera solo le righe che hanno lunghezza non zero. Per ciascuna di queste righe, e1 determina se la somma degli elementi della riga è multiplo di k. 
e1 ritorna true se tutte le righe di lunghezza non zero hanno somma degli elementi multiplo di k, e se almeno una riga con queste caratteristiche esiste. In tale caso, il massimo di tutte le somme deve essere scritto nell'intero puntato da pMaxSum.
In ogni altro caso e1 restituisce false. */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const int k, int *pMaxSum) 
{
    size_t sum = 0;
    size_t sum_max = 0;
    size_t full_rows = 0;
    size_t ret = false;

    for (size_t r=0; r<rows; r++)
    {
        sum = 0;

        if (rags[r] > 0)
        {
            full_rows += 1;

            for (size_t c=0; c<rags[r]; c++)
            {
                sum += mat[r][c];
            }

            if (sum % k == 0) 
            {
                ret += 1;
            }
        }

        if (sum > sum_max)
        {
            sum_max = sum;
        }
    }

    if (ret == full_rows && ret != 0)
    {
        *pMaxSum = sum_max;
    }

    return ret == full_rows && ret != 0;
}