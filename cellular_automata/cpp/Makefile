# CELLULAR AUTOMATA VISUALIZER (CPP) MAKEFILE
# - JAMES DELEON

# PATHS
INC_DIR = inc
SRC_DIR = src
TEST_DIR = tests

# FLAGS
CXXFLAGS = --std=c++17 -I$(INC_DIR) -I$(SRC_DIR) -I$(TEST_DIR)
SDLFLAGS = `/usr/bin/pkg-config sdl2 --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

# BUILD DIRECTIVES
all: cellular_automata tests
tests: test test_mouseclick

# MAIN EXE
cellular_automata: cell.o grid.o renderwindow.o main.o $(INC_DIR)/*.h
	$(CXX) $(CXXFLAGS) cell.o grid.o renderwindow.o main.o $(SDLFLAGS) -o cellular_automata
	echo "Success."

# TEST EXE
test: test.o cell.o grid.o $(INC_DIR)/*.h
	$(CXX) $(CXXFLAGS) test.o cell.o grid.o -o test
	echo "Success."

test_mouseclick: test_mouseclick.o $(INC_DIR)/*.h
	$(CXX) $(CXXFLAGS) test_mouseclick.o $(SDLFLAGS) -o test_mouseclick
	echo "Success."

# SRC COMPILE
main.o: main.cpp $(INC_DIR)/*.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(SDLFLAGS) -o main.o

cell.o: $(SRC_DIR)/cell.cpp $(INC_DIR)/*.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/cell.cpp -o cell.o

grid.o: $(SRC_DIR)/grid.cpp $(INC_DIR)/*.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/grid.cpp -o grid.o

renderwindow.o: $(SRC_DIR)/renderwindow.cpp $(INC_DIR)/*.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/renderwindow.cpp $(SDLFLAGS) -o renderwindow.o

test.o: $(TEST_DIR)/test.cpp $(INC_DIR)/*.h
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/test.cpp -o test.o

test_mouseclick.o: $(TEST_DIR)/test_mouseclick.cpp $(INC_DIR)/*.h
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/test_mouseclick.cpp $(SDLFLAGS) -o test_mouseclick.o

# HOUSEKEEPING
clean:
	rm -f *.o *.gch *~ test cellular_automata test_mouseclick

# END FILE