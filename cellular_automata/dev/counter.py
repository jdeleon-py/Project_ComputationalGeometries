import pygame
from pygame.locals import QUIT, MOUSEBUTTONDOWN
import random

class Counter:
	'''
	ADAPTED FROM: http://programarcadegames.com/index.php?chapter=array_backed_grids&lang=en
	- click on a cell to get how many alive neighbors it has
	- Note: make the GUI such that user can toggle between wrapping and unwrapping canvases
	'''
	BLACK = (0, 0, 0)
	WHITE = (255, 255, 255)
	DIM = 4

	def __init__(self) -> None:
		pygame.init()
		pygame.display.set_caption("Neighbor Counter 1")
		self.screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
		self.clock = pygame.time.Clock()
		self.grid = [[random.choice([0, 1]) for _ in range(0, Counter.DIM)] for _ in range(0, Counter.DIM)]
		self.cell_width = WINDOW_WIDTH / Counter.DIM
		self.cell_height = WINDOW_HEIGHT / Counter.DIM
		self.running = True

	def check_neighbors(self, i: int, j: int) -> int:
		num_alive = 0
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
		for row in range(0, Counter.DIM):
			for col in range(0, Counter.DIM):
				color = Counter.BLACK
				if row == 0 or col == 0 or row == Counter.DIM - 1 or col == Counter.DIM - 1:
					self.grid[row][col] = 0
				if self.grid[row][col] == 1: color = Counter.WHITE
				pygame.draw.rect(surface = self.screen,
								 color = color, 
								 rect = [self.cell_width * col, 
								 		 self.cell_height * row, 
								 		 self.cell_width, 
								 		 self.cell_height]
				)

	def cell_state(self) -> None:
		for row in range(1, Counter.DIM - 1):
			for column in range(1, Counter.DIM - 1):
				alive = self.check_neighbors(row, column)
				print("Cell ({0},{1}) has {2} alive neighbors.".format(row, column, alive))

	def run(self) -> None:
		while self.running:
			self.screen.fill(Counter.WHITE)
			for event in pygame.event.get():
				if event.type == QUIT: self.running = False
				elif event.type == MOUSEBUTTONDOWN: self.cell_state()
			self.draw_grid()
			pygame.display.flip()
			self.clock.tick(60)

if __name__ == "__main__":
	WINDOW_WIDTH = 512
	WINDOW_HEIGHT = 512

	game = Counter()
	game.run()
	pygame.quit()
