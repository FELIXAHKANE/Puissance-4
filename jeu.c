#include "jeu.h"

void afficheGrille(matrixBool M)
{
	int i;
	int j;
	printf("\n");
	printf("\033[34m  1   2   3   4   5   6   7\n");
	for(i=0; i<M.Hauteur; i++) {
		printf("| ");
		for(j=0; j<M.Largeur; j++) {
			if(M.mat[i][j][0] == 1) {
				if(M.mat[i][j][1] == 0) {
					//Alors c'est rouge
					printf("\033[31mo");
				}
				else {
					//Sinon c'est jaune
					printf("\033[33mo");
				}
			}
			else {
				printf(" ");
			}

			printf("\033[34m | ");
		}
		printf("\n");
		printf("-----------------------------\n");
	}
}

void lireCaractere(char *str) 
{ 

    char caractere = 0;
    caractere = getchar(); // On lit le premier chiffre
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer) 
    while (getchar() != '\n') ;

    str[0] = caractere; 
}

coord calculCoord(matrixBool M, int colonne, coord coordonnee)
{
	// met le jeton à l'emplacement demandé
	int hauteur = M.Hauteur - 1;
	colonne = colonne - 1;
	while(M.mat[hauteur][colonne][0] != 0){
		if(hauteur == 0 && M.mat[hauteur][colonne][0] != 0) {
			printf("Bah fallait pas continuer sur cette colonne .... Partie ANNULEE\n");
			exit(1);	
		}
		hauteur = hauteur - 1;
	}

	coordonnee.x = hauteur;
	coordonnee.y = colonne;

	return coordonnee;
}

void tour(matrixBool M, int couleurJoueur) 
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

	M.mat[coordonnee.x][coordonnee.y][0] = 1;
	if(couleurJoueur == 0) {
		M.mat[coordonnee.x][coordonnee.y][1] = 0;
	}
	else {
		M.mat[coordonnee.x][coordonnee.y][1] = 1;
	}
}

void tourReseau(matrixBool M, int couleurJoueur, int colonne) 
{
	coord coordonnee;
	coordonnee.x = 0;
	coordonnee.y = 0;
	coordonnee = calculCoord(M, colonne, coordonnee);

	M.mat[coordonnee.x][coordonnee.y][0] = 1;
	if(couleurJoueur == 0) {
		M.mat[coordonnee.x][coordonnee.y][1] = 0;
	}
	else {
		M.mat[coordonnee.x][coordonnee.y][1] = 1;
	}
}

int VerifVertR(matrixBool M, int x, int y)
{
	int Bool = 0;
	int compteur = 0;
	while(x >= 0 && Bool == 0) {
		if(M.mat[x][y][0] == 1 && M.mat[x][y][1] == 0){
			x = x - 1;
			compteur = compteur + 1;
		}
		else {
			Bool = 1;
		}
	}
	return compteur;
}

int VerifHorR(matrixBool M, int x, int y)
{
	int Bool = 0;
	int compteur = 0;
	while(y < 7 && Bool == 0) {
		if(M.mat[x][y][0] == 1 && M.mat[x][y][1] == 0){
			y = y + 1;
			compteur = compteur + 1;
		}
		else {
			Bool = 1;
		}
	}
	return compteur;
}

int VerifDiagR(matrixBool M, int i, int j)
{
	int Bool = 0;
	int compteur = 0;
	int x = i;
	int y = j;
	while(y < 7 && x >= 0 && Bool == 0) {
		if(M.mat[x][y][0] == 1 && M.mat[x][y][1] == 0){
			y = y + 1;
			x = x - 1;
			compteur = compteur + 1;
		}
		else {
			Bool = 1;
		}
	}

	if(compteur != 4) {
		compteur = 0;
		Bool = 0;
		x = i;
		y = j;
		while(y >= 0 && x >= 0 && Bool == 0) {
			if(M.mat[x][y][0] == 1 && M.mat[x][y][1] == 0){
				y = y - 1;
				x = x - 1;
				compteur = compteur + 1;
			}
			else {
				Bool = 1;
			}
		}
	}
	return compteur;
}

int VerifVertJ(matrixBool M, int x, int y)
{
	int Bool = 0;
	int compteur = 0;
	while(x >= 0 && Bool == 0) {
		if(M.mat[x][y][0] == 1 && M.mat[x][y][1] == 1){
			x = x - 1;
			compteur = compteur + 1;
		}
		else {
			Bool = 1;
		}
	}
	return compteur;
}

int VerifHorJ(matrixBool M, int x, int y)
{
	int Bool = 0;
	int compteur = 0;
	while(y < 7 && Bool == 0) {
		if(M.mat[x][y][0] == 1 && M.mat[x][y][1] == 1){
			y = y + 1;
			compteur = compteur + 1;
		}
		else {
			Bool = 1;
		}
	}
	return compteur;
}

int VerifDiagJ(matrixBool M, int i, int j)
{
	int Bool = 0;
	int compteur = 0;
	int x = i;
	int y = j;
	while(y < 7 && x >= 0 && Bool == 0) {
		if(M.mat[x][y][0] == 1 && M.mat[x][y][1] == 1){
			y = y + 1;
			x = x - 1;
			compteur = compteur + 1;
		}
		else {
			Bool = 1;
		}
	}

	if(compteur != 4) {
		compteur = 0;
		Bool = 0;
		x = i;
		y = j;
		while(y >= 0 && x >= 0 && Bool == 0) {
			if(M.mat[x][y][0] == 1 && M.mat[x][y][1] == 1){
				y = y - 1;
				x = x - 1;
				compteur = compteur + 1;
			}
			else {
				Bool = 1;
			}
		}
	}

	return compteur;
}

int CalculPuissance4(matrixBool M)
{
	//Cas Rouge
	int i,j;
	int compteur = 0;
	for(i = M.Hauteur-1; i >= 0; i--) {
		for(j = 0; j < M.Largeur; j++) {
			if(M.mat[i][j][0] == 1 && M.mat[i][j][1] == 0) {
				compteur = VerifVertR(M, i, j);
				if (compteur == 4){
					printf("\n\033[37mLES ROUGES GAGNEENT!!!!!!!!!!\n");
					return 1;
				}
				compteur = VerifHorR(M,i,j);
				if (compteur == 4){
					printf("\n\033[37mLES ROUGES GAGNEENT!!!!!!!!!!\n");
					return 1;
				}
				compteur = VerifDiagR(M,i,j);
				if (compteur == 4){
					printf("\n\033[37mLES ROUGES GAGNEENT!!!!!!!!!!\n");
					return 1;
				}
			}
		}
	}

	//Cas Jaune
	for(i = M.Hauteur-1; i >= 0; i--) {
		for(j = 0; j < M.Largeur; j++) {
			if(M.mat[i][j][0] == 1 && M.mat[i][j][1] == 1) {
				compteur = VerifVertJ(M, i, j);
				if (compteur == 4){
					printf("\n\033[37mLES JAUNES GAGNEENT!!!!!!!!!!\n");
					return 1;
				}
				compteur = VerifHorJ(M,i,j);
				if (compteur == 4){
					printf("\n\033[37mLES JAUNES GAGNEENT!!!!!!!!!!\n");
					return 1;
				}
				compteur = VerifDiagJ(M,i,j);
				if (compteur == 4){
					printf("\n\033[37mLES JAUNES GAGNEENT!!!!!!!!!!\n");
					return 1;
				}
			}
		}
	}

	return 0;
}