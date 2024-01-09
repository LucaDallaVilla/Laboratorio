    /* Scrivere ua funzione iterativa e1 con le seguenti caratteristiche:

    e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi;
    e1 modifica in-place la matrice irregolare;
    e1 non modifica la riga 0;
    per ciascuna riga i>0, la funzione e1 scorre gli elementi e filtra via tutti gli elementi che compaiono sulla riga precedente;
    e1 restituisce true se esiste almeno una riga che è stata modificata. */

    /* {0, -9, -2},
    {-4, -9, -9}}; */

    #include <stdio.h>
    #include <stdbool.h>


    void set_curr_row(size_t rows, size_t cols, int mat[rows][cols],
                        int curr_row[], size_t curr_len, size_t row,
                        size_t rags[])
    {
        for (int i=0; i<curr_len; i++)
        {
            mat[row][i] = curr_row[i];
        }

        rags[row] = curr_len;
    }

    void set_prev_row(size_t rows, size_t cols, int mat[rows][cols],
                        size_t row, int prev_row[], size_t rags[])
    {
        for (int i=0; i<rags[row]; i++)
        {
            prev_row[i] = mat[row][i];
        }
    }

    bool check_rows(int number, int prev_row[],
                    size_t prev_len)
    {
        bool ret = true;

        for (size_t i=0; i<prev_len; i++)
        {
            if (number == prev_row[i])
            {
                ret = false;
            }
        }

        return ret;
    }

    bool e1(const size_t rows, const size_t cols, 
            int mat[rows][cols], size_t rags[rows]) 
    {
        bool ret = false;
        int prev_row[cols];
        int curr_row[cols];
        size_t counter = 0;
        set_prev_row(rows, cols, mat, 0, prev_row, rags);

        for (size_t r=1; r<rows; r++)
        {
            for (size_t c=0; c<rags[r]; c++)
            {
                if (check_rows(mat[r][c], prev_row, rags[r-1]))
                {
                    curr_row[counter] = mat[r][c];
                    counter++;
                }
                else
                {
                    ret = true;
                }
            }

            set_curr_row(rows, cols, mat, curr_row, counter, r, rags);
            set_prev_row(rows, cols, mat, r, prev_row, rags);
            counter = 0;
        }

        return ret;
    }