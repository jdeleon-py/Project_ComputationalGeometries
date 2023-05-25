# John Conway's Game of Life Script

import pygame
from pygame.locals import QUIT, MOUSEBUTTONDOWN
from PIL import Image
import random
import glob

class Automata:
	'''
	METHODS:
		- ability to check the state of a cell's neighbors
		- ability to draw a grid of pixels (both the grid 
			and individual cell are of variable size)
		- ability to save frames of the epoch, then
			to be string together at the end of the epoch in GIF format
		- ability to change the state of a cell based on the
			state's of the cell's neighbors
		- ability to run the simulation in pygame continuously 
			until a maximum generation has been reached

	ATTRIBUTES:
		- tuple representing the color black
		- tuple representing the color white

		- a canvas width and height, by units of pixels
		- square dimension of the grid composed of cells (DIM = 128 -> (128x128) cells)
		- a specified cell width and height based on the desired window and grid dimensions

		- a boolean to specify whether the epoch will be saved in GIF format
		- an int representing the increment of generations

		- an output filepath to store individual frames of the epoch
		- an output gif filepath that will be generated if desired
		- a limit of frames to be stored

		- randomly generated list of states corresponding to the number 
			of cells within the window
	'''
	FRAMES_FILEPATH = "../lib/outputs/conway/"
	OUTPUT_GIF = "test.gif"
	MAX_FRAMES = 2000

	BLACK = (0, 0, 0)
	WHITE = (255, 255, 255)

	DIM = 128
	WINDOW_WIDTH = 512
	WINDOW_HEIGHT = 512

	CELL_WIDTH = WINDOW_WIDTH / DIM
	CELL_HEIGHT = WINDOW_HEIGHT / DIM

	def __init__(self, save_frame: bool) -> None:
		pygame.init()
		pygame.display.set_caption("John Conway's Game of Life")
		self.screen = pygame.display.set_mode((Automata.WINDOW_WIDTH, Automata.WINDOW_HEIGHT))
		self.clock = pygame.time.Clock()
		self.grid = [[random.choice([0, 1]) for _ in range(0, Automata.DIM)] for _ in range(0, Automata.DIM)]
		self.save_frame = save_frame
		self.generation = 0
		self.running = True

	def check_neighbors(self, i: int, j: int, border: bool) -> int:
		'''
		- Moore Neighborhood
		- counts how many alive (state = 1) neighbors for the examined cell
		- only examines the cells inside the perimeter cells of the window
		'''
		num_alive = 0
		if border == True: 
			if self.grid[i - 1][j - 1] == 1: num_alive += 1 
			if self.grid[i - 1][j + 0] == 1: num_alive += 1 
			if self.grid[i - 1][j + 1] == 1: num_alive += 1
			if self.grid[i + 0][j - 1] == 1: num_alive += 1
			if self.grid[i + 0][j + 1] == 1: num_alive += 1
			if self.grid[i + 1][j - 1] == 1: num_alive += 1
			if self.grid[i + 1][j + 0] == 1: num_alive += 1
			if self.grid[i + 1][j + 1] == 1: num_alive += 1
			return num_alive

	def draw_grid(self) -> None:
		'''
		- itertively sets the "border" cells to black (state = 0)
		- draws each rectangle (cell) onto the window
		- initially each cell is colored black, but if the state is "alive",
			the cell will change it's state to "1"
		'''
		for row in range(0, Automata.DIM):
			for col in range(0, Automata.DIM):
				color = Automata.BLACK
				if row in [0, Automata.DIM - 1] or col in [0, Automata.DIM - 1]:
					self.grid[row][col] = 0
				if self.grid[row][col] == 1: color = Automata.WHITE
				pygame.draw.rect(surface = self.screen,
								 color = color, 
								 rect = [Automata.CELL_WIDTH * col,
								 		 Automata.CELL_HEIGHT * row, 
								 		 Automata.CELL_WIDTH, 
								 		 Automata.CELL_HEIGHT]
				)

	def make_gif(self) -> None:
		'''
		- gathers the frames saved and sorts them by their order in generation
		- the arguments of the save() function are unknown
		'''
		print('Making GIF...')
		imgs = glob.glob(Automata.FRAMES_FILEPATH + '*.png')
		sort_func = lambda index: int(index.split('frame')[1].split('.')[0])
		imgs.sort(reverse = False, key = sort_func)
		frames = [Image.open(img) for img in imgs]
		frames[0].save(Automata.OUTPUT_GIF, 
					   format = 'GIF', 
					   append_images = frames[1:], 
					   save_all = True, 
					   duration = 30, 
					   loop = 0
		)
		print("GIF generation completed!")

	def eval_state(self) -> None:
		'''
		- a copy of the cell grid is initialized and each cell is set to "dead" (state = 0)
		- only examines the cells inside the border of the window
		- for John Conway's Game of Life:
			- Birth Rule: If a dead cell has exactly 3 alive neighbors, the cell turns alive.
			- Survival Rule: If an alive cell has 2 or 3 alive neighbors, the cell stays alive.
			- Underpopulation Rule: If an alive cell has less than 2 alive neighbors, the cell turns dead.
			- Overpopulation Rule: If an alive cell has more than 3 alive neighbors, the cell turns dead.
		- the grid copy adjusts the current iteration and then replaces 
			the original grid as the "next generation"
		'''
		grid_copy = [[0 for _ in range(0, Automata.DIM)] for _ in range(0, Automata.DIM)]
		for row in range(1, Automata.DIM - 1):
			for column in range(1, Automata.DIM - 1):
				alive = self.check_neighbors(row, column, border = True)
				if alive < 2 and self.grid[row][column] == 1: grid_copy[row][column] = 0
				elif (alive in [2, 3]) and self.grid[row][column] == 1: grid_copy[row][column] = 1
				elif alive > 3 and self.grid[row][column] == 1: grid_copy[row][column] = 0
				elif alive == 3 and self.grid[row][column] == 0: grid_copy[row][column] = 1
		self.grid = grid_copy

	def run(self) -> None:
		'''
		- simulation runs as long as the generation does not exceed the maximum allowed number of frames
		- holding the mouse button down restarts the simulation
		- for each generation, the cell is examined and it's next state is determined
		- saves an image of the current generation if the user desires
		'''
		while self.running:
			if self.generation > Automata.MAX_FRAMES: self.running = False
			self.screen.fill(Automata.WHITE)
			for event in pygame.event.get():
				if event.type == QUIT: self.running = False
				elif event.type == MOUSEBUTTONDOWN: self.__init__(save_frame = self.save_frame)
			self.eval_state()
			self.draw_grid()
			pygame.display.flip()
			self.clock.tick(30)
			if self.save_frame == True:
				pygame.image.save(self.screen, 
								  Automata.FRAMES_FILEPATH + "frame{}.png".format(self.generation)
				)
			self.generation += 1
		if self.save_frame == True: self.make_gif()

if __name__ == "__main__":
	game = Automata(save_frame = False)
	game.run()
	pygame.quit()
