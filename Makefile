all: main.o ia.o jeu.o matrices.o
	gcc main.o ia.o jeu.o matrices.o -o Puissance4

main.o: main.c ia.h
	gcc -c main.c -o main.o

ia.o: ia.c matrices.h
	gcc -c ia.c -o ia.o

jeu.o: jeu.c matrices.h
	gcc -c jeu.c -o jeu.o

matrices.o: matrices.c 
	gcc -c matrices.c -o matrices.o

# suppression des fichiers temporaires
clean:
	rm -rf *.o