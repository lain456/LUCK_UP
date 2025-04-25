prog: main.o jeu.o
	gcc main.o jeu.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

main.o: main.c jeu.h
	gcc -c main.c -g

jeu.o: jeu.c
	gcc -c jeu.c -g

clean:
	rm -f *.o prog
