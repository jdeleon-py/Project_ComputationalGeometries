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
all: tests m_explore j_explore mj_render
tests: test_mandelbrot test_julia test_render
animation: m_animate j_animate 

# EXE COMMANDS
# explore the mandelbrot set, click and drag to zoom onto a segment
m_explore: color.o mandelbrot.o renderwindow.o m_explore.o $(INC_DIR)/*.h
	gcc $(CFLAGS) color.o mandelbrot.o renderwindow.o m_explore.o $(SDLFLAGS) -o m_explore
	echo "Success."

# explore a julia set, click and drag to zoom onto a segment
# enter a seed value to render a particular julia set (Re(z), Im(z))
j_explore: color.o mandelbrot.o renderwindow.o j_explore.o $(INC_DIR)/*.h
	gcc $(CFLAGS) color.o mandelbrot.o renderwindow.o j_explore.o $(SDLFLAGS) -o j_explore
	echo "Success."

# explore a mandelbrot and julia split-screen
# click on a mandelbrot coordinate to render the cooresponding julia set
mj_render: color.o mandelbrot.o renderwindow.o mj_render.o $(INC_DIR)/*.h
	gcc $(CFLAGS) color.o mandelbrot.o renderwindow.o mj_render.o $(SDLFLAGS) -o mj_render
	echo "Success."

# TEST EXE
# verify functionality of mandelbrot sets with ASCII characters
test_mandelbrot: color.o mandelbrot.o test_mandelbrot.o $(INC_DIR)/*.h
	gcc $(CFLAGS) color.o mandelbrot.o test_mandelbrot.o -o test_mandelbrot
	echo "Success."

# verify functionality of julia sets with ASCII characters
test_julia: color.o mandelbrot.o test_julia.o $(INC_DIR)/*.h
	gcc $(CFLAGS) color.o mandelbrot.o test_julia.o -o test_julia
	echo "Success."

# TODO: remove this test and convert it to m_explore and j_explore
test_render: color.o mandelbrot.o renderwindow.o test_renderwindow.o $(INC_DIR)/*.h
	gcc $(CFLAGS) color.o mandelbrot.o renderwindow.o test_renderwindow.o $(SDLFLAGS) -o test_render
	echo "Success."

# UTILS COMPILE
color.o: $(SRC_DIR)/color.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/color.c -o color.o

# SRC COMPILE
mandelbrot.o: $(SRC_DIR)/mandelbrot.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/mandelbrot.c -o mandelbrot.o

renderwindow.o: $(SRC_DIR)/renderwindow.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/renderwindow.c $(SDLFLAGS) -o renderwindow.o

test_mandelbrot.o: $(TEST_DIR)/test_mandelbrot.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_mandelbrot.c -o test_mandelbrot.o

test_julia.o: $(TEST_DIR)/test_julia.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_julia.c -o test_julia.o

test_renderwindow.o: $(TEST_DIR)/test_renderwindow.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/test_renderwindow.c $(SDLFLAGS) -o test_renderwindow.o

m_explore.o: $(SRC_DIR)/m_explore.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/m_explore.c $(SDLFLAGS) -o m_explore.o

j_explore.o: $(SRC_DIR)/j_explore.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/j_explore.c $(SDLFLAGS) -o j_explore.o

mj_render.o: $(SRC_DIR)/mj_render.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/mj_render.c $(SDLFLAGS) -o mj_render.o

# HOUSEKEEPING
clean:
	rm -f *.o *.gch *~ test_mandelbrot test_julia test_render m_explore j_explore mj_render

