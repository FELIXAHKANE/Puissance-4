#include "ia.h"
#include <unistd.h>

int main() 
{

	matrixBool Grille = alloueMatriceB();
	Grille = initMatriceB(Grille);
	char mode[1];
	int choix = 0;
	printf("\n\t\033[7m\033[1m       PUISSANCE 4       \033[0m \033[0m\n\n");

	/*printf("\tBonjour jeunes joueurs\n");
	printf("\tTu vas avoir l'immense privilège\n");
	printf("************De jouer au Puissance 4 développé par**********\n");
	printf("********************Lorenzo et Félix***********************\n");

	printf("\n\n\n \tQue le jeu commence!! \n\n\n");
	*/
	printf("Choisis ton mode de jeu :\n\t1 - Solo (IA)\n\t2 - Multiplayer\n");
	lireCaractere(mode);
	choix = atoi(mode);

	if (choix == 1) { /* SOLO MODE */
		printf("Joue seul(e)!\n");
		afficheGrille(Grille);
		int couleurJoueur;
		int Partie = 0;
		while(Partie == 0) {
			couleurJoueur = 0;

			printf("\033[37m \n\n******************************\n");
			printf("\tAu tour des rouges\n");
			printf("******************************\n\n");

			tour_joueur(Grille);
			afficheGrille(Grille);
			Partie = CalculPuissance4(Grille);

			if(Partie == 0){ /* IA */
				printf("\033[37m \n\n******************************\n");
				printf("\tAu tour de l'IA\n");
				printf("******************************\n\n");
				pose_aleatoire(Grille);
				afficheGrille(Grille);
				Partie = CalculPuissance4(Grille);
			}
		}

	}
	else {
		printf("\t MULTIPLAYER GAME\n");
		afficheGrille(Grille);
		int couleurJoueur;
		int Partie = 0;
		while(Partie == 0) {
			couleurJoueur = 0;

			printf("\033[37m \n\n******************************\n");
			printf("\tAu tour des rouges\n");
			printf("******************************\n\n");

			tour(Grille, couleurJoueur);
			afficheGrille(Grille);
			Partie = CalculPuissance4(Grille);

			if(Partie == 0){
				couleurJoueur = 1;
				printf("\033[37m \n\n******************************\n");
				printf("Au tour des jaunes\n");
				printf("******************************\n\n");

				tour(Grille, couleurJoueur);
				afficheGrille(Grille);
				Partie = CalculPuissance4(Grille);
			}
		}
	}

	freeMatriceB(Grille);
	return 0;
}