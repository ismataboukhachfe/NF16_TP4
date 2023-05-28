#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED



struct Position {

	int numeroLigne;
	int ordre;
	int numeroPhrase;
	struct Position* suivant;

};

typedef struct Position T_Position;

struct Noeud {

	char* mot;
	int nbOccurences;
	T_Position* listePositions;
	struct Noeud* filsGauche;
	struct Noeud* filsDroit;

};

typedef struct Noeud  T_Noeud;


struct Index {

	 T_Noeud* racine;
	 int nbMotsDistincts;
	 int nbMotsTotal;

};

typedef struct Index T_Index;

T_Position* ajouterPosition(T_Position* listeP, int ligne, int ordre, int phrase);

int ajouterOccurence(T_Index* index, char* mot, int ligne, int ordre, int phrase) ; 

#endif






