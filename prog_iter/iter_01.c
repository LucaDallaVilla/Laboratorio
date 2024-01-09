#include <stdio.h>
#include <stdbool.h>

int e1(const size_t rows, const size_t cols, 
	   const int mat[rows][cols], const size_t rags[rows]) 
{
    size_t ret = 0;
    bool row_len = true;
    bool to_sum = true;

    for (size_t r=0; r<rows; r++)
    {
        if (rags[r] < rows && row_len)
        {
            row_len = false;
        }
    }

    if (row_len)
    {
        for (size_t r=0; r<rows; r++)
        {
            to_sum = true;
            
            for (size_t c=0; c<rags[r]; c++)
            {
                if (mat[r][c] % 7 == 0 && to_sum)
                {
                    ret += mat[r][c];
                    to_sum = false;
                }
            }
        }
    }

    return ret;
}