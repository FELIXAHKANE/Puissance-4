#include "matrices.h"
#define hauteur 6
#define largeur 7

matrix alloueMatrice() {
	int i;
	matrix res;
	res.Hauteur=hauteur;
	res.Largeur=largeur;
	res.mat=malloc(hauteur*sizeof(int*));
	for(i=0;i<hauteur;i++) {
		res.mat[i]=malloc(largeur*sizeof(int));
	}
	return res;
}


void afficheMatrice(matrix M) {
	int i;
	int j;
	for(i=0; i<M.Hauteur; i++) {
		printf("(");
		for(j=0; j<M.Largeur; j++) {
			printf("%d",M.mat[i][j]);
			printf("  ");
		}
		printf(")\n");
	}
}

void freeMatrice(matrix M){
	for(int i=0;i<M.Hauteur;i++) {
		free(M.mat[i]);
	}
	free(M.mat);
}

matrix initMatrice(matrix M) {
	for(int i=0;i<M.Hauteur;i++){
		for(int j=0; j<M.Largeur; j++) {
			M.mat[i][j]=0;
		}
	}
	return M;
}

matrixBool alloueMatriceB() {
	int i;
	matrixBool res;
	res.Hauteur=hauteur;
	res.Largeur=largeur;
	res.mat=malloc(hauteur*sizeof(int**));
	for(i=0;i<hauteur;i++) {
		res.mat[i]=malloc(largeur*sizeof(int*));
		for(int j=0; j<largeur; j++) {
			res.mat[i][j]=malloc(2*sizeof(int));
		}
	}
	return res;
}

void afficheMatriceB(matrixBool M) {
	int i;
	int j;
	for(i=0; i<M.Hauteur; i++) {
		printf("(");
		for(j=0; j<M.Largeur; j++) {
			printf("%d",M.mat[i][j][0]);
			printf("%d",M.mat[i][j][1]);
			printf("  ");
		}
		printf(")\n");
	}
}

void freeMatriceB(matrixBool M){
	for(int i=0;i<M.Hauteur;i++) {
		free(M.mat[i]);
	}
	free(M.mat);
}

matrixBool initMatriceB(matrixBool M) {
	for(int i=0;i<M.Hauteur;i++){
		for(int j=0; j<M.Largeur; j++) {
			M.mat[i][j][0]=0;
			M.mat[i][j][1]=0;
		}
	}
	return M;
}