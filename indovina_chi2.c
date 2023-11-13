#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_PERS 24

// I nomi dei soggetti fermati
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

int main(void) {
	char indizi[16];
	scanf("%15s", indizi);
	size_t num_sospetti = 0;

	for (size_t i=0; i<NUM_PERS; i++) { // per ogni soggetto
	    
	    // determina se tutti gli indizi sono soddisfatti
		bool tutti_indizi_soddisf = true;
		size_t j=0;
		while (indizi[j] && tutti_indizi_soddisf) { // per ogni indizio
			char f = tolower(indizi[j]);
			if (isupper(indizi[j])) {
			    // determina se f non esiste tra gli attributi del soggetto
			    bool non_esiste_attr = false;
				for (size_t k=0; attributi[i][k] && !non_esiste_attr; k++) {
					if (attributi[i][k] == f) // non ha attributo richiesto
						non_esiste_attr = true;
				}
				if (non_esiste_attr)
				    tutti_indizi_soddisf = false;
			}
			else {
			    // determina se f esiste tra gli attributi del soggetto
				bool esiste_attr = false;
				for (size_t k=0; attributi[i][k] && !esiste_attr; k++) {
					if (attributi[i][k] == f) // ha attributo richiesto
						esiste_attr = true;
				}
				if (!esiste_attr)
				    tutti_indizi_soddisf = false;
			}
			j++;
		}
        // e' sospetto se tutti gli indizi sono soddisfatti
		if (tutti_indizi_soddisf) {
			printf("%s\n", nomi[i]);
			num_sospetti++;
		}
	}

	printf("%zu\n", num_sospetti);
}