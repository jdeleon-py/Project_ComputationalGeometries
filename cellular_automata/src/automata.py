import pygame
from pygame.locals import QUIT, MOUSEBUTTONDOWN
import random

class Automata:
	'''
	'''
	BLACK = (0, 0, 0)
	WHITE = (255, 255, 255)

	DIM = 128
	WINDOW_WIDTH = 512
	WINDOW_HEIGHT = 512

	CELL_WIDTH = WINDOW_WIDTH / DIM
	CELL_HEIGHT = WINDOW_HEIGHT / DIM

	def __init__(self) -> None:
		pygame.init()
		pygame.display.set_caption("John Conway's Game of Life")
		self.screen = pygame.display.set_mode((Automata.WINDOW_WIDTH, Automata.WINDOW_HEIGHT))
		self.clock = pygame.time.Clock()
		self.grid = [[random.choice([0, 1]) for _ in range(0, Automata.DIM)] for _ in range(0, Automata.DIM)]
		self.running = True

	def check_neighbors(self, i: int, j: int, border: bool) -> int:
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
		for row in range(0, Automata.DIM):
			for col in range(0, Automata.DIM):
				color = Automata.BLACK
				if row == 0 or col == 0 or row == Automata.DIM - 1 or col == Automata.DIM - 1:
					self.grid[row][col] = 0
				if self.grid[row][col] == 1: color = Automata.WHITE
				pygame.draw.rect(surface = self.screen,
								 color = color, 
								 rect = [Automata.CELL_WIDTH * col,
								 		 Automata.CELL_HEIGHT * row, 
								 		 Automata.CELL_WIDTH, 
								 		 Automata.CELL_HEIGHT]
				)

	def cell_state(self) -> None:
		grid_copy = [[0 for _ in range(0, Automata.DIM)] for _ in range(0, Automata.DIM)]
		for row in range(1, Automata.DIM - 1):
			for column in range(1, Automata.DIM - 1):
				alive = self.check_neighbors(row, column, border = True)
				if (self.grid[row][column] == 1) and (alive < 2): grid_copy[row][column] = 0
				elif (alive == 2 or alive == 3) and self.grid[row][column] == 1: grid_copy[row][column] = 1
				elif alive > 3 and self.grid[row][column] == 1: grid_copy[row][column] = 0
				elif alive == 3 and self.grid[row][column] == 0: grid_copy[row][column] = 1
				else: pass
		self.grid = grid_copy

	def run(self) -> None:
		while self.running:
			self.screen.fill(Automata.WHITE)
			for event in pygame.event.get():
				if event.type == QUIT: self.running = False
				elif event.type == MOUSEBUTTONDOWN: self.__init__()
			self.cell_state()
			self.draw_grid()
			pygame.display.flip()
			self.clock.tick(60)

if __name__ == "__main__":
	game = Automata()
	game.run()
	pygame.quit()
