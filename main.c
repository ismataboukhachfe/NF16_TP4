#include "tp4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

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


void libererNoeud(T_Noeud* noeud) {
    if (noeud == NULL) {
        return; // Si le noeud est NULL, il n'y a rien à libérer
    }

    // Libérer le mot
    if (noeud->mot != NULL) {
        free(noeud->mot);
        noeud->mot = NULL;
    }

    // Libérer la liste des positions
    libererPositions(noeud->listePositions);
    noeud->listePositions = NULL;

    // Libérer les sous-noeuds (fils gauche et fils droit)
    libererNoeud(noeud->filsGauche);
    libererNoeud(noeud->filsDroit);

    // Enfin, libérer le noeud lui-même
    free(noeud);
    noeud = NULL;  
}
void libererIndex(T_Index* index) {
    if (index != NULL) {
        // Libérer la racine (assumant que T_Noeud est également une structure)
        // Si la racine contient d'autres structures à libérer, il faudra également les libérer de manière récursive
        free(index->racine);
        index->racine = NULL; 
        // Réinitialiser les compteurs à zéro
        index->nbMotsDistincts = 0;
        index->nbMotsTotal = 0;

        // Libérer la structure Index elle-même
        free(index);
        index = NULL; 
    }
}


int main() {

	T_Index* arbre = NULL;
	char* mot ="bonjour";
	ajouterOccurence(arbre, mot, 1, 1, 1);

	/*T_Position *listePositions = NULL;
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
*/
}
