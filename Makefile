all: main.o ia.o jeu.o matrices.o Joueur1.o
	gcc main.o ia.o jeu.o matrices.o Joueur1.o -o Puissance4

Joueur2: Joueur2.o ia.o jeu.o matrices.o
	gcc Joueur2.o ia.o jeu.o matrices.o -o Joueur2

main.o: main.c ia.h
	gcc -c main.c -o main.o

ia.o: ia.c matrices.h
	gcc -c ia.c -o ia.o

jeu.o: jeu.c matrices.h
	gcc -c jeu.c -o jeu.o

matrices.o: matrices.c 
	gcc -c matrices.c -o matrices.o

Joueur1.o: Joueur1.c matrices.h jeu.h ia.h
	gcc -c Joueur1.c -o Joueur1.o

Joueur2.o: Joueur2.c ia.h
	gcc -c Joueur2.c -o Joueur2.o

# suppression des fichiers temporaires
clean:
	rm -rf *.o