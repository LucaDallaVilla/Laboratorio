#include <stdio.h>

void somma_max(int list[]) {
    int attempt[sizeof(list) / sizeof(list[0])];
    int i = 0;
    int sum = 0;
    
    while (1) {
        attempt[i] = list[i];

        for (int j=0; j < (sizeof(attempt) / sizeof(attempt[0])); j++) {
            sum = sum + attempt[j];
        }

        if (sum >= 30) {
            int list[(sizeof(attempt) / sizeof(attempt[0]) - 1)];
            for (int j=0; j < (sizeof(attempt) / sizeof(attempt[0]) - 1); j++) {
                printf("%d", list[j]);
            }

            return;
        }

\\        i++;
    }
}

int main() {
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    somma_max(list);

    return 0;
}