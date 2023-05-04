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
tests: test_point

# MAIN EXE (...)

# TEST EXE
test_point: point.o test_point.o $(INC_DIR)/*.h
	gcc $(CFLAGS) point.o test_point.o -o test_point
	rm -f *.o *.gch *~
	echo "Success."


# SRC COMPILE
point.o: $(SRC_DIR)/point.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/point.c -o point.o 

test_point.o: $(TEST_DIR)/test_point.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_point.c -o test_point.o


# HOUSEKEEPING
clean:
	rm -f test_point 

