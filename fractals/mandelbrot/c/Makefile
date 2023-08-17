# MANDELBROT VISUALIZER (C) MAKEFILE
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
tests: test_render

# MAIN EXE

# TEST EXE
test_mandelbrot: color.o mandelbrot.o test_mandelbrot.o $(INC_DIR)/*.h
	gcc $(CFLAGS) color.o mandelbrot.o test_mandelbrot.o -o test_mandelbrot
	echo "Success."

test_qtree: color.o quadtree.o test_qtree.o $(INC_DIR)/*.h
	gcc $(CFLAGS) color.o quadtree.o test_qtree.o -o test_qtree
	echo "Success."

test_render: color.o mandelbrot.o renderwindow.o test_renderwindow.o $(INC_DIR)/*.h
	gcc $(CFLAGS) color.o mandelbrot.o renderwindow.o test_renderwindow.o $(SDLFLAGS) -o test_render
	echo "Success."

# UTILS COMPILE
color.o: $(SRC_DIR)/color.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/color.c -o color.o

#file.o: $(SRC_DIR)/file.c $(INC_DIR)/*.h
#	gcc -c $(CFLAGS) $(SRC_DIR)/file.c -o file.o

# SRC COMPILE
mandelbrot.o: $(SRC_DIR)/mandelbrot.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/mandelbrot.c -o mandelbrot.o

quadtree.o: $(SRC_DIR)/quadtree.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/quadtree.c -o quadtree.o

renderwindow.o: $(SRC_DIR)/renderwindow.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/renderwindow.c $(SDLFLAGS) -o renderwindow.o

test_mandelbrot.o: $(TEST_DIR)/test_mandelbrot.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_mandelbrot.c -o test_mandelbrot.o

test_qtree.o: $(TEST_DIR)/test_quadtree.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_quadtree.c -o test_qtree.o

test_renderwindow.o: $(TEST_DIR)/test_renderwindow.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_renderwindow.c $(SDLFLAGS) -o test_renderwindow.o

# HOUSEKEEPING
clean:
	rm -f *.o *.gch *~ test_mandelbrot test_render test_qtree

