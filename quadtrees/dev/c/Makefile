# QUADTREES (C) MAKEFILE
# - JAMES DELEON

# PATHS
INC_DIR = inc
SRC_DIR = src
TEST_DIR = tests

# FLAGS
CFLAGS = -g -I$(INC_DIR) -I$(SRC_DIR) -I$(TEST_DIR)
SDLFLAGS = `/usr/bin/pkg-config sdl2 --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

# BUILD DIRECTIVES
all: tests
tests: test_point test_qtree

# MAIN EXE (...)

# TEST EXE
test_point: point.o test_point.o $(INC_DIR)/*.h
	gcc $(CFLAGS) point.o test_point.o -o test_point
	echo "Success."

test_qtree: point.o quadtree.o test_qtree.o $(INC_DIR)/*.h
	gcc $(CFLAGS) point.o quadtree.o test_qtree.o -o test_qtree
	echo "Success."

# SRC COMPILE
point.o: $(SRC_DIR)/point.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/point.c -o point.o 

quadtree.o: $(SRC_DIR)/quadtree.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/quadtree.c -o quadtree.o

test_point.o: $(TEST_DIR)/test_point.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_point.c -o test_point.o

test_qtree.o: $(TEST_DIR)/test_quadtree.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_quadtree.c -o test_qtree.o

# HOUSEKEEPING
clean:
	rm -f *.o *.gch *~ test_point test_qtree

