# AUTOMATA PYGAME CLASS

import pygame
from pygame.locals import QUIT, MOUSEBUTTONDOWN
import random
from grid import Grid
from hyperparameters import Hyperparameters as h

class Game:
	'''
	'''
	def __init__(self) -> None:
		pygame.init()
		pygame.display.set_caption("John Conway's Game of Life")
		self.screen = pygame.display.set_mode((h.WINDOW_WIDTH, h.WINDOW_HEIGHT))
		self.clock = pygame.time.Clock()
		self.grid = Grid()
		self.running = True

	def draw_grid(self) -> None:
		for row in range(0, h.DIM):
			for col in range(0, h.DIM):
				color = h.BLACK
				if row in [0, h.DIM - 1] or col in [0, h.DIM - 1]: 
					self.grid.grid[row][col].state = 0
				if self.grid.grid[row][col].state == 1: color = h.WHITE
				pygame.draw.rect(surface = self.screen,
								 color = color, 
								 rect = [h.CELL_WIDTH * col, 
								 		 h.CELL_HEIGHT * row, 
								 		 h.CELL_WIDTH, 
								 		 h.CELL_HEIGHT]
				)

	def run(self) -> None:
		while self.running:
			self.screen.fill(h.WHITE)
			for event in pygame.event.get():
				if event.type == QUIT: self.running = False
				elif event.type == MOUSEBUTTONDOWN: self.__init__()
			self.grid.eval_state()
			self.draw_grid()
			pygame.display.flip()
			self.clock.tick(30)


if __name__ == "__main__":
	game = Game()
	game.run()
	pygame.quit()
