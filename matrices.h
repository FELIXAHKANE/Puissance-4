#include <stdio.h>
#include <stdlib.h>

typedef struct matrix matrix;

struct matrix{
	int ** mat;
	int Hauteur;
	int Largeur;
};

matrix alloueMatrice();

void afficheMatrice(matrix M);

void freeMatrice(matrix M);

matrix initMatrice(matrix M);

typedef struct coord coord;

struct coord{
	int x;
	int y;
};

typedef struct matrixBool matrixBool;

struct matrixBool{
	int *** mat;
	int Hauteur;
	int Largeur;
};

matrixBool alloueMatriceB();

void afficheMatriceB(matrixBool M);

void freeMatriceB(matrixBool M);

matrixBool initMatriceB(matrixBool M);