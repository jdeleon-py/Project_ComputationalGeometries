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
all: qtree tests
tests: test_point test_qtree test_render

# MAIN EXE
qtree: point.o quadtree.o renderwindow.o main.o $(INC_DIR)/*.h
	gcc $(CFLAGS) point.o quadtree.o renderwindow.o main.o $(SDLFLAGS) -o qtree
	echo "Success."

main.o: main.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) main.c $(SDLFLAGS) -o main.o

# TEST EXE
test_point: point.o test_point.o $(INC_DIR)/*.h
	gcc $(CFLAGS) point.o test_point.o -o test_point
	echo "Success."

test_qtree: point.o quadtree.o test_qtree.o $(INC_DIR)/*.h
	gcc $(CFLAGS) point.o quadtree.o test_qtree.o -o test_qtree
	echo "Success."

test_render: quadtree.o point.o renderwindow.o test_renderwindow.o $(INC_DIR)/*.h
	gcc $(CFLAGS) point.o quadtree.o renderwindow.o test_renderwindow.o $(SDLFLAGS) -o test_render
	echo "Success."

# SRC COMPILE
point.o: $(SRC_DIR)/point.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/point.c -o point.o 

quadtree.o: $(SRC_DIR)/quadtree.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/quadtree.c -o quadtree.o

renderwindow.o: $(SRC_DIR)/renderwindow.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/renderwindow.c $(SDLFLAGS) -o renderwindow.o

test_point.o: $(TEST_DIR)/test_point.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_point.c -o test_point.o

test_qtree.o: $(TEST_DIR)/test_quadtree.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_quadtree.c -o test_qtree.o

test_renderwindow.o: $(TEST_DIR)/test_renderwindow.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_renderwindow.c $(SDLFLAGS) -o test_renderwindow.o

# HOUSEKEEPING
clean:
	rm -f *.o *.gch *~ qtree test_point test_qtree test_render

