CXXFLAGS = --std=c++17
SDLFLAGS = `/usr/bin/pkg-config sdl2 --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

all: test cellular_automata test_mouseclick

debug: CXXFLAGS += -g

cellular_automata: cell.o grid.o renderwindow.o main.o *.h
	$(CXX) $(CXXFLAGS) cell.o grid.o renderwindow.o main.o $(SDLFLAGS) -o cellular_automata

test: test.o cell.o grid.o *.h
	$(CXX) $(CXXFLAGS) test.o cell.o grid.o -o test

test_mouseclick: test_mouseclick.o *.h
	$(CXX) $(CXXFLAGS) test_mouseclick.o $(SDLFLAGS) -o test_mouseclick

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(SDLFLAGS) -o main.o

test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

test_mouseclick.o: test_mouseclick.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_mouseclick.cpp $(SDLFLAGS) -o test_mouseclick.o

cell.o: cell.cpp *.h
	$(CXX) $(CXXFLAGS) -c cell.cpp -o cell.o

grid.o: grid.cpp *.h
	$(CXX) $(CXXFLAGS) -c grid.cpp -o grid.o

renderwindow.o: renderwindow.cpp *.h
	$(CXX) $(CXXFLAGS) -c renderwindow.cpp $(SDLFLAGS) -o renderwindow.o

clean:
	rm -f *.o *.gch *~ test cellular_automata test_mouseclick

