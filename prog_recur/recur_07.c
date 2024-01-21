#include <stdio.h>
#include <stdbool.h>

void e2R(size_t *p_aVal, int a[], const int min,
        const int max, size_t n, size_t c) 
{
    if (n < *p_aVal) {
        if (a[n] >= min && a[n] <= max) {
            a[c] = a[n];
            c++;
        }

        e2R(p_aVal, a, min, max, n+1, c);
    } else {
        *p_aVal = c;
    }
}

void e2(size_t *p_aVal, int a[], const int min, const int max) 
{
    e2R(p_aVal, a, min, max, 0, 0);
}