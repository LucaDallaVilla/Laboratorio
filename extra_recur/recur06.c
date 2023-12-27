#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void e2R(size_t* p_aVal, int a[], int b[], const int min, const int max,
        size_t n, size_t count) 
{
    if (n < *p_aVal) {
        if (b[n] >= min && b[n] <= max) {
            a[count] = b[n];
            *p_aVal = count;
            e2R(p_aVal, a, b, min, max, n+1, count+1);
        } else {
            *p_aVal = count;
            e2R(p_aVal, a, b, min, max, n+1, count);
        }
    }
}

void e2(size_t *p_aVal, int a[], const int min, const int max) 
{
    int b[*p_aVal];
    assert(&b != &a);
    e2R(p_aVal, a, b, min, max, 0, 0);
}

int main(void) {
    size_t p_aVal = 4;
    int a[] = {1,2,3,4};
    int min = 2;
    int max = 3;

    e2(&p_aVal, a, min, max);

    for (int i=0; i<p_aVal; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("p_aVal = %ld\n", p_aVal);
}