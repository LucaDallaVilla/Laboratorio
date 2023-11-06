#include <stdio.h>

int contaOccorrenze(int array[], int length, int n);

int main() {
    int array[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    printf("%d\n", contaOccorrenze(array, 9, 2));
}

int contaOccorrenze(int array[], int length, int n) {
    int counter = 0;
    for (int i=0; i<length; i++) {
        if (array[i] == n) {
            counter++;
        }
    }
    return counter;
}