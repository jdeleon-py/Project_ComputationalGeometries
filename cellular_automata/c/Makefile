# CELLULAR AUTOMATA (C) MAKEFILE

# VPATH = src:inc

CFLAGS = -g -I/opt/homebrew/include/SDL2
SDLFLAGS = -L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

all: cellular_automata

cellular_automata: cell.o grid.o renderwindow.o main.o *.h
	gcc $(CFLAGS) cell.o grid.o renderwindow.o main.o -o cellular_automata $(SDLFLAGS)

main.o: main.c *.h
	gcc -c $(CFLAGS) -c main.c -o main.o

cell.o: cell.c *.h
	gcc -c $(CFLAGS) cell.c -o cell.o
	echo "Success."

grid.o: grid.c *.h
	gcc -c $(CFLAGS) grid.c -o grid.o
	echo "Success."

renderwindow.o: renderwindow.c *.h
	gcc -c $(CFLAGS) renderwindow.c -o renderwindow.o $(SDLFLAGS)
	echo "Success."

clean:
	rm -f *.o *.gch *~ cellular_automata

