#include <stdio.h>
#define NUM_PERS 24

const char* nomi[NUM_PERS] = {
    "Claire","Eric",   "Maria", "George","Bernard","Sam",    "Tom",    "Paul",
    "Joe",   "Frans",  "Anne",  "Max",   "Alex",   "Philip", "Bill",   "Anita",  
    "David", "Charles","Herman","Peter", "Susan",  "Robert", "Richard","Alfred", 
};

// Gli attributi dei soggetti fermati, codificati come stringa
const char* attributi[NUM_PERS] = {
    "drco", "bc",   "dtc", "wc",   "tcg",  "wpo",  "npzo", "wo",  
    "bo",   "r",    "dn",  "nfsg", "nfs",  "nal",  "rpal", "dblz", 
    "ba",   "bfs",  "rpg", "wszg", "dwls", "tlzg", "tpfa", "rfz", 
};

int main() {
    char input[NUM_PERS];
    int input_length;

    scanf("%s%n", input, &input_length);
    // printf("SAS: %d\n", input_length);

    for (int i=0; i<input_length; i++) {
        for (int j=0; j<NUM_PERS; j++) {
            for (int k=0; k<4; k++) {
                if (input[i] == attributi[j][k]) {
                    printf("%d", i);
                }
            }
        }
    }

    return 0;
} 