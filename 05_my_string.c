#include <stdio.h>
#include <stdbool.h>
#include <time.h>
// NON includere <string.h> !

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// copia nell’intervallo [dstStart, dstStart+strLen) i caratteri 
// della stringa str1 seguiti dai caratteri della stringa str2. 
// Ricordarsi di aggiungere il terminatore alla fine.
// Se l’intervallo non ha spazio sufficiente, la copia termina 
// quando lo spazio nell’intervallo è esaurito. 
void my_concat(char* dstStart, const size_t strLen,
			  const char* str1, const char* str2);

// Scrivere una funzione my_equal che prende in ingresso due 
// stringhe e restituisce true se sono identiche, carattere per carattere,
// altrimenti restituisce false.
bool my_equal(char *stringa1, char *stringa2);

// copia nell’intervallo [dstStart, dstStart+strLen) i caratteri della
// stringa str in modo tale che ogni carattere viene copiato N volte.
// Ricordarsi di aggiungere il terminatore alla fine.
// Se l’intervallo non ha spazio sufficiente, lo sdoppiamento termina 
// quando lo spazio nell’intervallo è esaurito. 
// Esempio: la stringa "aBc" con N=3 produce "aaaBBBccc" 
//          (assumendo sufficiente spazio)
void n_uplica_lettere(char* dstStart, const size_t strLen,
			        const char* str, const size_t N);

// restituisce la lunghezza della stringa str
size_t my_strlen(char* str);

// restituisce true se la stringa str inizia con il prefisso prefix,
// altrimenti false.
// NB. La stringa vuota "" è prefisso di ogni stringa.
bool startswith(char* stringa, char* prefix);

// restituisce true se la stringa str contiene la sottostringa sub,
// false altrimenti.
// size_t* left e size_t* right sono due puntatori a variabili che
// vengono usate per restituire:
//	- l'indice del primo carattere di str che fa parte della sottostringa sub e 
//  - l'indice del primo carattere di str che non fa parte della sottostringa sub.
// NB. La stringa vuota "" è contenuta in ogni stringa.
// NB. Consideriamo la prima occorrenza di sub in str.
bool contains(const char* str, const char* sub, size_t* left, size_t* right);


//------------------------------------------------------------------

int main(void) 
{
	const char* s = "Prog";
	const char* s2 = "rammazione";

#   define NBUF1  20
#   define NBUF2  10
	char buffer1[NBUF1], buffer2[NBUF2];

	printf("Testing my_concat()\n");
	my_concat(buffer1, NBUF1, s, s2);
	printf("%-20s   [Atteso: Programmazione]\n", buffer1);

	my_concat(buffer2, NBUF2, s, s2);
	printf("%-20s   [Atteso: Programma]\n", buffer2);

	my_concat(buffer1, 0, s, s2); // non deve rompersi, ne copiare nulla

	puts("");

	printf("Testing my_equal()\n");
	printf("%d [Atteso: 1]\n", my_equal(buffer2, "Programma"));
	printf("%d [Atteso: 0]\n", my_equal(buffer2, "banana"));
	printf("%d [Atteso: 1]\n", my_equal("ananas", "ananas"));
	printf("%d [Atteso: 0]\n", my_equal("ananas", "mela"));
	printf("%d [Atteso: 0]\n", my_equal("melagrana", "mela"));
	printf("%d [Atteso: 0]\n", my_equal("mela", "melagrana"));
	printf("%d [Atteso: 1]\n", my_equal("", ""));

	puts("");
	printf("Testing n_uplica_lettere()\n");
	n_uplica_lettere(buffer1, NBUF1, "aBc", 3);
	printf("%-20s   [Atteso: aaaBBBccc]\n", buffer1);

	n_uplica_lettere(buffer2, NBUF2, "XyZ", 4);
	printf("%-20s   [Atteso: XXXXyyyyZ]\n", buffer2);

	n_uplica_lettere(buffer2,NBUF2, "", 4);
	printf("%-20s   [Atteso: ]\n", buffer2);

	n_uplica_lettere(buffer2, NBUF2, "ciao", 0);
	printf("%-20s   [Atteso: ]\n", buffer2);

	n_uplica_lettere(buffer2, NBUF2, "mela", 2);
	printf("%-20s   [Atteso: mmeella]\n", buffer2);

	puts("");

	printf("Testing my_strlen()\n");
	printf("%2zu [Atteso: 0]\n", my_strlen(""));
	printf("%2zu [Atteso: 16]\n", my_strlen("programmazione-1"));
	printf("%2zu [Atteso: 6]\n", my_strlen("banana"));
	printf("%2zu [Atteso: 1]\n", my_strlen("a"));

	puts("");
	printf("Testing startswith()\n");
	printf("%d [Atteso: 1]\n", startswith("programmazione", "programmazione"));
	printf("%d [Atteso: 1]\n", startswith("programmazione", "programma"));
	printf("%d [Atteso: 0]\n", startswith("programma", "programmazione"));
	printf("%d [Atteso: 1]\n", startswith("", ""));
	printf("%d [Atteso: 1]\n", startswith("programmazione", ""));

	puts("");
	printf("Testing contains()\n");

	size_t left, right;

	bool res = contains("programmazione", "prog", &left, &right);
	printf("ret=%d    [%zu, %zu)  |	Atteso: 1   [0, 4)\n", res, left, right);

	res = contains("stringhe", "programmazione", &left, &right);
	printf("ret=%d    [%zu, %zu)  |	Atteso: 0   [0, 0)\n", res, left, right);

	res = contains("programmazione", "", &left, &right);
	printf("ret=%d    [%zu, %zu)  |	Atteso: 1   [0, 0)\n", res, left, right);

	res = contains("", "", &left, &right);
	printf("ret=%d    [%zu, %zu)  |	Atteso: 1   [0, 0)\n", res, left, right);

	res = contains("programmazione", "azione", &left, &right);
	printf("ret=%d    [%zu, %zu) |	Atteso: 1   [8  14)\n", res, left, right);
}


// copia nell’intervallo [dstStart, dstStart+strLen) i caratteri 
// della stringa str1 seguiti dai caratteri della stringa str2. 
// Ricordarsi di aggiungere il terminatore alla fine.
// Se l’intervallo non ha spazio sufficiente, la copia termina 
// quando lo spazio nell’intervallo è esaurito. 
void my_concat(char* dstStart, const size_t strLen,
			  const char* str1, const char* str2)
{
	int counter = 0;
	for (int s=0; str1[s]!='\0' && counter<strLen-1; s++) {
		dstStart[counter] = str1[s];
		counter++;
	}
	for (int s=0; str2[s]!='\0' && counter<strLen-1; s++) {
		dstStart[counter] = str2[s];
		counter++;
	}
	dstStart[counter] = '\0';
}

// Scrivere una funzione my_equal che prende in ingresso due 
// stringhe e restituisce true se sono identiche, carattere per carattere,
// altrimenti restituisce false.
bool my_equal(char *stringa1, char *stringa2) 
{
	bool ver1 = 1;
	bool ver2 = 1;

	// occorrono due cicli perché non conosciamo
	// la lunghezza dei 2 array
	// cicla rispetto alla prima stringa
    for (int i=0; stringa1[i]!='\0' && ver1; i++) {
        // printf("%d == %d\n", stringa1[i], stringa2[i]);
        if (stringa1[i] == stringa2[i]) {
            ver1 = 1;
        } else {
            ver1 = 0;
        }
    }

	// cicla rispetto alla seconda stringa
	for (int i=0; stringa2[i]!='\0' && ver2; i++) {
        // printf("%d == %d\n", stringa1[i], stringa2[i]);
        if (stringa1[i] == stringa2[i]) {
            ver2 = 1;
        } else {
            ver2 = 0;
        }
    }

	// se entrambi i cicli ritornano true
	// le stringhe sono uguali
    return ver1 && ver2;
}

// copia nell’intervallo [dstStart, dstStart+strLen) i caratteri della
// stringa str in modo tale che ogni carattere viene copiato N volte.
// Ricordarsi di aggiungere il terminatore alla fine.
// Se l’intervallo non ha spazio sufficiente, lo sdoppiamento termina 
// quando lo spazio nell’intervallo è esaurito. 
// Esempio: la stringa "aBc" con N=3 produce "aaaBBBccc" 
//          (assumendo sufficiente spazio)
void n_uplica_lettere(char* dstStart, const size_t strLen,
			        const char* str, const size_t N)
{
	char copia[strLen];
	for (int i=0; i<strLen; i++) {
		copia[i] = dstStart[i];
	}

	int counter = 0;
	for (int i=0; i<strLen; i++) {
		for (int j=0; j<N && counter<strLen-1; j++) {
			dstStart[counter] = str[i];
			counter++;
		}
	}

	dstStart[counter] = '\0';
}

//------------------------------------------------------------------

size_t my_strlen(char* str)
{
	int length = 0;

	for (int i=0; str[i]!='\0'; i++) {
		length += 1;
	}

	return length;
}

// restituisce true se la stringa str inizia con il prefisso prefix,
// altrimenti false.
// NB. La stringa vuota "" è prefisso di ogni stringa.
bool startswith(char* string, char* prefix)
{
	bool result = true;
	bool run = true;

	for (int i=0; prefix[i]!='\0' && run; i++) {
		if (string[i] != prefix[i]) {
			result = false;
			run = false;
		}
	}

	return result;
}

// restituisce true se la stringa str contiene la sottostringa sub,
// false altrimenti.
// size_t* left e size_t* right sono due puntatori a variabili che
// vengono usate per restituire:
//	- l'indice del primo carattere di str che fa parte della sottostringa sub
//  - l'indice del primo carattere di str che non fa parte della sottostringa sub.
// NB. La stringa vuota "" è contenuta in ogni stringa.
// NB. Consideriamo la prima occorrenza di sub in str.
bool contains(const char* str, const char* sub, size_t* left, size_t* right)
{
	// per ogni lettera di str, si va a verificare se la sottostringa sub
	// è contenuta in str a partire da quella lettera
	bool cicla = true;
	bool trovata = false;

	printf("STR: %s\n", str);
	printf("SUB: %s\n", sub);
	
	for (size_t i=0; str[i]!='\0' && !trovata; i++) {
		for (size_t j=0; sub[j]!='\0' && cicla; j++) {
			if (str[i+j] != sub[j]) {
				// al primo carattere differente
				// si esce dal ciclo annidato
				cicla = false;
			}
			else {
				if (j == 0) {
					*left = i;
				}
				*right = i + j + 1;
			}
		}
		// si è trovata una sottostringa
		if (!cicla) {
			// si ritenta con una nuova lettera i-esima di str
			*right = 0;
			cicla = true;
		} else {
			trovata = true;
		}
	}

	// se la sottostringa è vuota, 
	// esiste in str per definizione
	if (sub[0] == '\0') {
		trovata = true;
	}

	return trovata;
}