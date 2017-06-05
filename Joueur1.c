#include "Joueur1.h" 
 
void Joueur1(matrixBool M)
{
    
    int erreur = 0;
    
 
    SOCKET sock;
    SOCKADDR_IN sin;
    SOCKET csock;
    SOCKADDR_IN csin;
    
    socklen_t recsize = sizeof(csin);
    int sock_err;
 
    /* Si les sockets Windows fonctionnent */
    if(!erreur)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
 
        /* Si la socket est valide */
        if(sock != INVALID_SOCKET)
        {
            printf("\033[37m\nLa socket %d est maintenant ouverte en mode TCP/IP\n", sock);
 
            /* Configuration */
            sin.sin_addr.s_addr    = htonl(INADDR_ANY);   /* Adresse IP automatique */
            sin.sin_family         = AF_INET;             /* Protocole familial (IP) */
            sin.sin_port           = htons(PORT);         /* Listage du port */
            sock_err = bind(sock, (SOCKADDR*)&sin, sizeof(sin));
 
            /* Si la socket fonctionne */
            if(sock_err != SOCKET_ERROR)
            {
                /* Démarrage du listage (mode server) */
                sock_err = listen(sock, 0);
                printf("Listage du port %d...\n", PORT);
 
                /* Si la socket fonctionne */
                if(sock_err != SOCKET_ERROR)
                {
                    /* Attente pendant laquelle le client se connecte */
                    printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);        
 
                    csock = accept(sock, (SOCKADDR*)&csin, &recsize);
                    printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
                    
                    /*
                    Début du code Puissance 4
                    */
                    int couleurJoueur;
                    int Partie = 0;
                    printf("\n\nVous êtes les rouges!!\n");
                    while(Partie == 0) {
                        couleurJoueur = 0;
                        int colonne = 0;

                        printf("\033[37m \n\n******************************\n");
                        printf("\tAu tour des rouges\n");
                        printf("******************************\n\n");

                        // Choix de la colonne
                        char str[1];
                        lireCaractere(str);
                        //printf("str : %s\n", str);
                        colonne = atoi(str);

                        if(colonne >= 10) {
                            colonne = colonne/10;
                        }

                        while(colonne < 1 || colonne >7) {
                            printf("S'il vous plaît veuillez choisir un chiffre entre 1 et 7 inclus\n");
                            lireCaractere(str);
                            colonne = atoi(str);
                        }

                        tourReseau(M, couleurJoueur, colonne);
                        afficheGrille(M);
                        Partie = CalculPuissance4(M);
                        char buffer[1];
                        sprintf(buffer,"%d", colonne);
                        sock_err = send(csock, buffer, 1, 0);
                        

                        if(Partie == 0){

                            printf("\033[37m \n\n******************************\n");
                            printf("Au tour des jaunes\n");
                            printf("******************************\n\n");

                            while(recv(csock, buffer, 1, 0) == SOCKET_ERROR) {
                                printf("%s\n", buffer);
                            }
                            
                            //printf("Recu : %s\n", buffer);

                            colonne = atoi(buffer);
                            couleurJoueur = 1;
                            

                            tourReseau(M, couleurJoueur, colonne);
                            afficheGrille(M);
                            Partie = CalculPuissance4(M);
                        }
                    }

 
                    /* Il ne faut pas oublier de fermer la connexion (fermée dans les deux sens) */
                    shutdown(csock, 2);
                }
            }
            else {
                printf("La socket met du temps a se fermer, attendez un peu\n");
            }
 
            /* Fermeture de la socket */
            printf("Fermeture de la socket...\n");
            close(sock);
            printf("Fermeture du serveur terminee\n");
        }

    }
 
    /* On attend que l'utilisateur tape sur une touche, puis on ferme */
    getchar();
}