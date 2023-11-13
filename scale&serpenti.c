#include <stdio.h>
#include <stdbool.h>

const int scale[8][2] = {
    {1, 38}, {4, 14}, {8, 30}, {21, 42}, {28, 76}, {50, 67}, {71, 92}, {80, 99}
};

const int serpi[8][2] = {
    {32, 10}, {36, 6}, {48, 26}, {62, 18}, {88, 24}, {95, 56}, {97, 78}, {-1, -1}
};

// Avanza la posizione del giocatore nella casella *pos
// in funzione del lancio del dado.
// Parametri:
//   dado   La quantità ottenuta dal lancio del dado (compresa tra 1 e 6)
//  *pos    La cella del giocatore che muove
// Ritorna true se il giocatore gioca ancora il prossimo turno, false altrimenti.
// Al ritorno, il valore di *pos è stato modificato aggiungendo il lancio 
// del dado, ed applicando tutte le rimanenti reole sulle scale e sulle serpi
bool muovi_giocatore(int dado, int* pos) {
	*pos += dado;
    for (int i=0; i<9; i++) {
        if (*pos == serpi[i][0]) {
            *pos = serpi[i][1];
        } else if (*pos == scale[i][0]) {
            *pos = scale[i][1];
        }
    }
    return dado == 6;
}

//------------------------------------------------------------------------------
// LEGGERE MA NON MODIFICARE IL CODICE SEGUENTE

// Simula il lancio di un dado a 6 facce
int lancia_dado() {
	return (rand() % 6) + 1;
}

// Realizza i turni del gioco delle scale e delle serpi
void scale_e_serpi(void) {
	int pos1 = 1, pos2 = 1; // la posizione dei due giocatori, inizialmente 1
	int turno = 1; 			// puo' valere 1 o 2

	// Esegui i turni
	while (pos1<100 && pos2<100) {
		// il giocatore lancia il dado
		int dado = lancia_dado();
		// muovi il giocatore attivo, e determina chi gioca il prossimo turno
		if (turno == 1) { 
			// muove il giocatore 1
			if (muovi_giocatore(dado, &pos1) == false)
				turno = 2; // passa il turno al giocatore 2
		}
		else { 
			// muove il giocatore 2
			if (muovi_giocatore(dado, &pos2) == false)
				turno = 1; // passa il turno al giocatore 1
		}
	}
	// Stampa il vincitore e le posizioni finali dei due giocatori
	printf("%d %d %d\n", turno, pos1, pos2);
}