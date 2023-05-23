#include "tp4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficherPositions(T_Position * listeP) {
	T_Position *current = listeP;
	while (current != NULL) {
		printf("Ligne: %d , Ordre: %d, Phrase: %d\n", current->numeroLigne, current->ordre, current->numeroPhrase);
		current = current->suivant;
	}
}

void libererPositions(T_Position* listeP) {
    T_Position * current = listeP;
    T_Position * next;

    while (current != NULL) {
        next = current->suivant;
        free(current);
        current = next;
    }

    listeP = NULL;
}


int main (){

	T_Position *listePositions = NULL;
	//listePositions = malloc(sizeof(T_Position)) ;

	// Test the function by adding positions
	listePositions = ajouterPosition(listePositions, 1, 1, 1);
	listePositions = ajouterPosition(listePositions, 2, 2, 1);
	listePositions = ajouterPosition(listePositions, 2, 3, 2);
	listePositions = ajouterPosition(listePositions, 3, 1, 2);
	listePositions = ajouterPosition(listePositions, 4, 1, 1);

	// Print the positions
	afficherPositions(listePositions);
    libererPositions(listePositions);
	return 0;
}