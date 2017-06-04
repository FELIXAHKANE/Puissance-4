#include "ia.h"
#include <time.h>

void tour_joueur(matrixBool M) 
{
	// Choix de la colonne
	char str[1];
	lireCaractere(str);
	int colonne = atoi(str);

	while(colonne < 1 || colonne >7) {
		printf("S'il vous plaît veuillez choisir un chiffre entre 1 et 7 inclus\n");
		lireCaractere(str);
		colonne = atoi(str);
	}
	coord coordonnee;
	coordonnee.x = 0;
	coordonnee.y = 0;
	coordonnee = calculCoord(M, colonne, coordonnee);
	// Presence
	M.mat[coordonnee.x][coordonnee.y][0] = 1;
	//Couleur
	M.mat[coordonnee.x][coordonnee.y][1] = 0;
}

void pose_aleatoire(matrixBool M) {
	int random_col = rand() % 7;
	coord coordonnee;
	coordonnee.x = 0;
	coordonnee.y = 0;
	coordonnee = calculCoord(M, random_col, coordonnee);
	M.mat[coordonnee.x][coordonnee.y][0] = 1;
	M.mat[coordonnee.x][coordonnee.y][1] = 1;
}