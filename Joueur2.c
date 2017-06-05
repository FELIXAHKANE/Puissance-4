#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#include "ia.h"

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

 
#include <stdio.h>
#include <stdlib.h>
#define PORT 23
 
 
 
int main()
{
    int erreur = 0;
    
    int sock_err;

    matrixBool Grille = alloueMatriceB();
    Grille = initMatriceB(Grille);
    afficheGrille(Grille);

    SOCKET sock;
    SOCKADDR_IN sin;
    char buffer[1] = "";
 
    /* Si les sockets Windows fonctionnent */
    if(!erreur)
    {
        /* Création de la socket */
        sock = socket(AF_INET, SOCK_STREAM, 0);
 
        /* Configuration de la connexion */
        sin.sin_addr.s_addr = inet_addr("127.0.0.1");
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORT);
 
        /* Si l'on a réussi à se connecter */
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
        {
            printf("\033[37mConnection à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
            
            /*
            Début du code Puissance 4
            */
            int couleurJoueur;
            int Partie = 0;
            printf("\n\nVous êtes les jaunes!!\n");
            while(Partie == 0) {

                printf("\033[37m \n\n******************************\n");
                printf("Au tour des rouges\n");
                printf("******************************\n\n");

                while(recv(sock, buffer, 1, 0) == SOCKET_ERROR) {
                    printf("%s\n", buffer);
                }
                
                //printf("Recu : %s\n", buffer);
                int colonne = 0;
                
                colonne = atoi(buffer);
                couleurJoueur = 0;
                

                tourReseau(Grille, couleurJoueur, colonne);
                afficheGrille(Grille);
                Partie = CalculPuissance4(Grille);

                

                if(Partie == 0){
                    printf("\033[37m \n\n******************************\n");
                    printf("\tAu tour des jaunes\n");
                    printf("******************************\n\n");

                    couleurJoueur = 1;
                    // Choix de la colonne
                    char str[1];
                    lireCaractere(str);
                    //printf("str : %s\n", str);
                    int colonne2 = atoi(str);

                    if(colonne >= 10) {
                        colonne = colonne/10;
                    }

                    while(colonne2 < 1 || colonne2 >7) {
                        printf("S'il vous plaît veuillez choisir un chiffre entre 1 et 7 inclus\n");
                        lireCaractere(str);
                        colonne2 = atoi(str);
                        printf("%d\n", colonne2);
                    }

                    tourReseau(Grille, couleurJoueur, colonne2);
                    afficheGrille(Grille);
                    Partie = CalculPuissance4(Grille);
                    sprintf(buffer,"%d", colonne2);
                    sock_err = send(sock, buffer, 1, 0);
                }
            }
        }
        /* sinon, on affiche "Impossible de se connecter" */
        else
        {
            printf("Impossible de se connecter\n");
        }
 
        /* On ferme la socket */
        close(sock);
 
    }
 
    /* On attend que l'utilisateur tape sur une touche, puis on ferme */
    getchar();
 
    return EXIT_SUCCESS;
}