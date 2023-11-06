#include <stdio.h>
#include <string.h>
#define NUM_PERS 24

void stringCommon(char string1[], int length1, char string2[], int length2, char result[]);

int main() {
    char input[NUM_PERS];
    int input_length;

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

    // ottengo gli attributi del personaggio da indovinare
    // printf("Inserire gli attributi: ");
    scanf("%s%n", input, &input_length);
    // printf("SAS: %d\n", input_length);

    // printf("Nome\tAttr.\tInput\tComune\n");
    // puts("");

    int maxAttributes = 0;
    int indexes[NUM_PERS];
    int counter = 0;
    for (int i=0; i<NUM_PERS; i++) {
        char result[5];
        stringCommon(TODO, input_length, (char*)attributi[i], 5, result);
        // printf("%s\t%s\t%s\t%s\n", nomi[i], attributi[i], input, result);

        // ottiene il numero di attributi trovati
        int resultLength = 0;
        for (int i=0; i<5; i++) {
            if (result[i] != '\0') {
                resultLength++;
            }
        }
        // se i nuovi risultati sono di più dei precedenti salvo l'indice del nuovo risultato
        if (resultLength == maxAttributes) {
            maxAttributes = resultLength;
            indexes[counter] = i;
            counter++;
        }
        else if (resultLength > maxAttributes) {
            for (int j=0; j<NUM_PERS; j++) {
                indexes[j] = '\0';
            }
            counter = 0;
            maxAttributes = resultLength;
            indexes[counter] = i;
            counter++;
        }
    }

    int i = 0;
    while (indexes[i] != '\0') {
        printf("%s\n", nomi[indexes[i]]);
        i++;
    }
    printf("%d", i);

    // for (int i=0; i<sizeof(indexes)/sizeof(indexes[0]); i++) {
    //     printf("%s\n", nomi[indexes[i]]);
    // }

    // puts("");
    return 0;
}

void stringCommon(char string1[], int length1, char string2[], int length2, char result[]) {
    // elimino tutti gli elementi dell'array
    for (int i=0; i<5; i++) {
        result[i] = '\0';
    }
    
    int c = 0;
    for (int i=0; i<length1; i++) {
        for (int j=0; j<length2; j++) {
            if (string1[i] == string2[j]) {
                result[c] = string1[i];
                c++;
            }
        }
    }
}