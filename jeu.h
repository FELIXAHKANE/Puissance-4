#include "matrices.h"

void afficheGrille(matrixBool M);

void lireCaractere(char *str) ;

coord calculCoord(matrixBool M, int colonne, coord coordonnee);

void tour(matrixBool M, int couleurJoueur);

int VerifVertR(matrixBool M, int x, int y);

int VerifHorR(matrixBool M, int x, int y);

int VerifDiagR(matrixBool M, int i, int j);

int VerifVertJ(matrixBool M, int x, int y);

int VerifHorJ(matrixBool M, int x, int y);

int VerifDiagJ(matrixBool M, int i, int j);

int CalculPuissance4(matrixBool M);

//Fonction utile pour le jeu réseau

void tourReseau(matrixBool M, int couleurJoueur, int colonne);