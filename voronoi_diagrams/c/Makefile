# VORONOI DIAGRAM VISUALIZER (C) MAKEFILE
# - JAMES DELEON

# PATHS
INC_DIR = inc
SRC_DIR = src
TEST_DIR = tests

# FLAGS
LIBFLAGS = -lm
CFLAGS = -g -I/opt/homebrew/include/SDL2 -I$(INC_DIR) -I$(SRC_DIR) -I$(TEST_DIR)
SDLFLAGS = -L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# BUILD DIRECTIVES
all: tests
tests: test_site test_quadtree test_render test_analysis

# MAIN EXE

# TEST EXE
test_site: site.o test_site.o $(INC_DIR)/*.h
	gcc $(CFLAGS) site.o test_site.o -o test_site $(LIBFLAGS)
	echo "Success."

test_quadtree: site.o quadtree.o test_quadtree.o $(INC_DIR)/*.h
	gcc $(CFLAGS) site.o quadtree.o test_quadtree.o -o test_quadtree $(LIBFLAGS) $(SDLFLAGS)
	echo "Success."

test_render: site.o quadtree.o renderwindow.o test_renderwindow.o $(INC_DIR)/*.h
	gcc $(CFLAGS) site.o quadtree.o renderwindow.o test_renderwindow.o -o test_render $(LIBFLAGS) $(SDLFLAGS)
	echo "Success."

test_analysis: site.o quadtree.o renderwindow.o analysis.o $(INC_DIR)/*.h
	gcc $(CFLAGS) site.o quadtree.o renderwindow.o analysis.o -o test_analysis $(LIBFLAGS) $(SDLFLAGS)
	echo "Success."

# UTILS COMPILE

# SRC COMPILE
site.o: $(SRC_DIR)/site.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/site.c -o site.o

quadtree.o: $(SRC_DIR)/quadtree.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/quadtree.c -o quadtree.o

renderwindow.o: $(SRC_DIR)/renderwindow.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/renderwindow.c -o renderwindow.o $(SDLFLAGS)

test_site.o: $(TEST_DIR)/test_site.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_site.c -o test_site.o

test_quadtree.o: $(TEST_DIR)/test_quadtree.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_quadtree.c -o test_quadtree.o

test_renderwindow.o: $(TEST_DIR)/test_renderwindow.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_renderwindow.c -o test_renderwindow.o $(SDLFLAGS)

analysis.o: $(TEST_DIR)/analysis.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/analysis.c -o analysis.o $(SDLFLAGS)

# HOUSEKEEPING
clean:
	rm -f *.o *.gch *~ test_site test_quadtree test_render test_analysis

