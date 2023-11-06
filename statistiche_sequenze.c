#include <stdio.h>

void leggiSequenza(int array[], int length);
void stampaStatistiche(int array[], int length);

int main() {
    int length = 20;
    int inputs[length]; // TODO
    do {
        // ottiene un'array di int dall'utente
        // finché non viene inserito come primo numero un 0.
        leggiSequenza(inputs, length);
        stampaStatistiche(inputs, length);
    } while (inputs[0] != 0);

    return 0;
}

void leggiSequenza(int inputs[], int length) {
    // pulisco tutti gli elementi della vecchia array inputs
    for (int i=0; i<length; i++) {
        inputs[i] = '\0';
    }

    int i = -1;
    do {
        i++;
        scanf("%d", &inputs[i]);
    } while (inputs[i] != 0);
    inputs[i] = '\0';
}

void stampaStatistiche(int inputs[], int length) {
    int sum = 0;
    int squareSum = 0;
    int maxNum = 0;

    if (inputs[0] == 0) {
        return;
    }

    for (int i=0; i<length; i++) {
        printf("%d ", inputs[i]);
        sum += inputs[i];
        squareSum += inputs[i] * inputs[i];
        if (inputs[i] > maxNum) {
            maxNum = inputs[i];
        }
    }

    printf("%d %d %d", sum, squareSum, maxNum);
    puts("");
}