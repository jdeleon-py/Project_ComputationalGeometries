import pygame
from pygame.locals import QUIT, MOUSEBUTTONDOWN
import random

class Grid:
	'''
	ADAPTED FROM: http://programarcadegames.com/index.php?chapter=array_backed_grids&lang=en
	'''
	BLACK = (0, 0, 0)
	WHITE = (255, 255, 255)
	DIM = 128

	def __init__(self) -> None:
		pygame.init()
		pygame.display.set_caption("Array-Backed Grid")
		self.screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
		self.clock = pygame.time.Clock()
		self.grid = [[random.choice([0, 1]) for _ in range(0, Grid.DIM)] for _ in range(0, Grid.DIM)]
		self.cell_width = WINDOW_WIDTH / Grid.DIM
		self.cell_height = WINDOW_HEIGHT / Grid.DIM
		self.running = True

	def draw_grid(self) -> None:
		for row in range(0, Grid.DIM):
			for column in range(0, Grid.DIM):
				color = Grid.BLACK
				if self.grid[row][column] == 1: color = Grid.WHITE
				pygame.draw.rect(surface = self.screen,
								 color = color, 
								 rect = [self.cell_width * column, 
								 		 self.cell_height * row, 
								 		 self.cell_width, 
								 		 self.cell_height]
				)

	def cell_state(self) -> None:
		# Change the (x,y) screen coordinates to grid coordinates
		pos = pygame.mouse.get_pos()
		column = int(pos[0] // self.cell_width)
		row = int(pos[1] // self.cell_height)
		if self.grid[row][column] == 0: self.grid[row][column] = 1
		else: self.grid[row][column] = 0
		print("Mouse Coordinates: {0}; Grid Coordinates: ({1},{2})".format(pos, row, column))

	def run(self) -> None:
		while self.running:
			self.screen.fill(Grid.WHITE)
			for event in pygame.event.get():
				if event.type == QUIT: self.running = False
				elif event.type == MOUSEBUTTONDOWN: self.cell_state()
			self.draw_grid()
			pygame.display.flip()
			self.clock.tick(60)

if __name__ == "__main__":
	WINDOW_WIDTH = 512
	WINDOW_HEIGHT = 512

	game = Grid()
	game.run()
	pygame.quit()
