#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp4.h"
#include<stdbool.h>
#include<ctype.h>

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


int ajouterOccurence(T_Index* index, char* mot, int ligne, int ordre, int phrase) {

	tolower(mot);
	T_Noeud * nouveau_mot = NULL; 
	nouveau_mot = malloc(sizeof(T_Noeud));

	T_Position* listeP = NULL; 
	listeP = malloc(sizeof(T_Position));
	nouveau_mot->listePositions = ajouterPosition(listeP, ligne, ordre, phrase);
	nouveau_mot->filsDroit = NULL; 
	nouveau_mot->filsGauche = NULL;
	nouveau_mot->mot = mot;  // ON pourra avoir une erreur
	
	T_Noeud* racine = index->racine; 
	if (index == NULL) {

		index->racine = nouveau_mot; 
		index->nbMotsDistincts = 1;
		index->nbMotsTotal = 1;

		return 1; 

	} 
	else {
		T_Noeud* noeud_courant = racine; 
		T_Noeud* noeud_pere = NULL; 
		bool mot_exist = false; 
		bool plus_grand_que_noeud_pere; 
		while (noeud_courant != NULL) {

			noeud_pere = noeud_courant; 
			if (strcmp((noeud_courant->mot), mot) < 0) {
				plus_grand_que_noeud_pere = false;
				noeud_courant = noeud_courant->filsGauche; 

			}
			if (strcmp((noeud_courant->mot), mot) > 0) {
				plus_grand_que_noeud_pere = true; 
				noeud_courant = noeud_courant->filsDroit; 

			}
			if (strcmp((noeud_courant->mot), mot) == 0) {
				mot_exist = true; 
				break; 
			}

		}
		if (mot_exist == true) {

			ajouterPosition(noeud_courant->listePositions, ligne, ordre, phrase); 
			index->nbMotsTotal++;

		}
		else {
			if (plus_grand_que_noeud_pere == true) {

				noeud_pere->filsDroit = nouveau_mot;  
				index->nbMotsDistincts++; 
				index->nbMotsTotal++; 
				return 1; 
			}
			else {
				noeud_pere->filsGauche = nouveau_mot;
				index->nbMotsDistincts++;
				index->nbMotsTotal++;
				return 1; 

			}
			
		}

	}	
	return 0; 

}		


//3 
//strcmp

int indexerFichier(T_Index* index, char* filename) {






}






















