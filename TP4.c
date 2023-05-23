#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp4.h"



T_Position* ajouterPosition(T_Position* listeP, int ligne, int ordre, int phrase)
{

	T_Position* nouveau = NULL;
	nouveau = malloc(sizeof(T_Position));

	nouveau->numeroLigne = ligne;
	nouveau->ordre = ordre;
	nouveau->numeroPhrase = phrase;
	nouveau->suivant = NULL; 
	if (listeP == NULL) {

		nouveau->suivant = NULL;
		listeP = nouveau;
		return listeP;
	}

	T_Position* current2 = listeP;
	T_Position* current_exist = listeP;
	while (current_exist != NULL) {
		if ((current_exist->numeroLigne == ligne) && (current_exist->ordre == ordre) && (current_exist->numeroPhrase == phrase)) {

			printf("cette position existe deja");
			return listeP;

		}
		current_exist = current_exist->suivant;
	}
	T_Position* predecesseur = NULL;
	predecesseur = malloc(sizeof(T_Position));

	while ((current2 != NULL) && (current2->numeroLigne < ligne)  ) {

		predecesseur = current2;
		current2 = current2->suivant;


	}
	if (current2 == NULL) {

		predecesseur->suivant = nouveau;
		nouveau->suivant = NULL;
		return listeP;

	}
	if (current2->numeroLigne == ligne) {
		while (current2->numeroLigne == ligne) {

			if (ordre <= (current2->ordre)) {
				predecesseur->suivant = nouveau;
				nouveau->suivant = current2;
				return listeP;
			}
			else {

				//if(ordre > current2->ordre  ){
				while ( (current2 != NULL ) && (ordre > current2->ordre) ) {

					predecesseur = current2;
					current2 = current2->suivant;

				}
				if (current2 == NULL) {

					predecesseur->suivant = nouveau;
					nouveau->suivant = NULL;
					return listeP;

				}
				else {
					predecesseur->suivant = nouveau;
					nouveau->suivant = current2;
					return listeP;
				}

			}
		}
	}

	else {
		//current2->numeroLigne > ligne

		predecesseur->suivant = nouveau;
		nouveau->suivant = current2;
		return listeP;

	}

}

/*
int ajouterOccurence(T_Index* index, char* mot, int ligne, int ordre, int phrase) {

	T_Noeud * nouveau_mot = NULL; 
	nouveau_mot = malloc(sizeof(T_Noeud));

	T_Position* listeP = NULL; 
	listeP = malloc(sizeof(T_Position));
	nouveau_mot->listePositions = ajouterPostition(listeP, ligne, ordre, phrase);
	nouveau_mot->filsDroit = NULL; 
	nouveau_mot->filsGauche = NULL;
	nouveau_mot->mot = mot;  // ON pourra avoir une erreur
	index->nbMotsDistincts = 0;
	index->nbMotsTotal = 0; 

	if (index == NULL) {

		index->racine = nouveau_mot; 
		index->nbMotsDistincts++; 
		index->nbMotsTotal++; 
		return index; 
	} 


	

}	
*/



//strcmp























