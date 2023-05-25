# VORONOI DIAGRAM VISUALIZER (C) MAKEFILE
# - JAMES DELEON

# PATHS
INC_DIR = inc
SRC_DIR = src
TEST_DIR = tests

# FLAGS
LIBFLAGS = -lm
CFLAGS = -g -I$(INC_DIR) -I$(SRC_DIR) -I$(TEST_DIR)
SDLFLAGS = `/usr/bin/pkg-config sdl2 --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

# BUILD DIRECTIVES
all: tests
tests: test_site

# MAIN EXE

# TEST EXE
test_site: site.o test_site.o $(INC_DIR)/*.h
	gcc $(CFLAGS) site.o test_site.o -o test_site $(LIBFLAGS)
	echo "Success."

# UTILS COMPILE

# SRC COMPILE
site.o: $(SRC_DIR)/site.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/site.c -o site.o

test_site.o: $(TEST_DIR)/test_site.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_site.c -o test_site.o

# HOUSEKEEPING
clean:
	rm -f *.o *.gch *~ test_site

