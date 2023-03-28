CXXFLAGS = --std=c++2a

all: cellular_automata

cellular_automata: main.o cell.o grid.o *.h
	$(CXX) $(CXXFLAGS) main.o cell.o grid.o -o cellular_automata

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

cell.o: cell.cpp *.h
	$(CXX) $(CXXFLAGS) -c cell.cpp -o cell.o

grid.o: grid.cpp *.h
	$(CXX) $(CXXFLAGS) -c grid.cpp -o grid.o

clean:
	rm -f *.o *.gch *~ cellular_automata

