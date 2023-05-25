# CELLULAR AUTOMATA (C) MAKEFILE

# VPATH = src:inc

CFLAGS = -g
SDLFLAGS = `/usr/bin/pkg-config sdl2 --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

all: cellular_automata

cellular_automata: cell.o grid.o renderwindow.o main.o *.h
	gcc $(CFLAGS) cell.o grid.o renderwindow.o main.o $(SDLFLAGS) -o cellular_automata

main.o: main.c *.h
	gcc -c $(CFLAGS) -c main.c $(SDLFLAGS) -o main.o

cell.o: cell.c *.h
	gcc -c $(CFLAGS) cell.c -o cell.o

grid.o: grid.c *.h
	gcc -c $(CFLAGS) grid.c -o grid.o

renderwindow.o: renderwindow.c *.h
	gcc -c $(CFLAGS) renderwindow.c $(SDLFLAGS) -o renderwindow.o

clean:
	rm -f *.o *.gch *~ cellular_automata

