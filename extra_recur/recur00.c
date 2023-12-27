#include <stdio.h>
#include <stdbool.h>

void e2R(const int a[], const size_t left, const size_t right, size_t* p_bLen, int b[], const int val, int i) {
    if (left == right || i == *p_bLen) {
        *p_bLen = i;
    } else {
        if (a[left] > val) {
            b[i] = a[left]-val;
            i++;
        }
        e2R(a, left+1, right, p_bLen, b, val, i);
    }
}

void e2(const size_t aLen, const int a[], size_t* p_bLen, int b[], const int val)
{
	e2R(a, 0, aLen, p_bLen, b, val, 0);
}