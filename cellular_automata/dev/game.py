# AUTOMATA PYGAME CLASS

import json
import random
import pygame
from pygame.locals import QUIT, MOUSEBUTTONDOWN
from grid import Grid

class Game:
	'''
	DESCRIPTION:
		- visualizes the system with the pygame library

	METHODS:
		- ability to read out preset parameters
		- ability to draw a grid object every frame of the animation
		- ability to continuously run the animation unless specified
			otherwise

	ATTRIBUTES:
		- parameter dictionary
		- pygame initializers
		- initial and iteravely continuous grid object
		- cell width based on parameters
		- cell height based on parameters
	'''
	def __init__(self) -> None:
		self.params = self.define_params()
		pygame.init()
		pygame.display.set_caption("John Conway's Game of Life")
		self.screen = pygame.display.set_mode((self.params["Window Width"], self.params["Window Height"]))
		self.clock = pygame.time.Clock()
		self.grid = Grid()
		self.cell_width = int(self.params["Window Width"] / self.params["DIM"])
		self.cell_height = int(self.params["Window Height"] / self.params["DIM"])
		self.running = True

	def define_params(self) -> dict:
		'''
		- reads parameter json file and loads dict data
		'''
		with open("parameters.json", 'r') as file:
			data = json.load(file)
		file.close()
		return data

	def draw_grid(self) -> None:
		'''
		- assigns states to each cell in the grid object
		'''
		for row in range(0, self.params["DIM"]):
			for col in range(0, self.params["DIM"]):
				color = (0, 0, 0)
				if row in [0, self.params["DIM"] - 1] or col in [0, self.params["DIM"] - 1]: 
					self.grid.grid[row][col].state = 0
				if self.grid.grid[row][col].state == 1: color = (255, 255, 255)
				pygame.draw.rect(surface = self.screen,
								 color = color, 
								 rect = [self.cell_width * col, 
								 		 self.cell_height * row, 
								 		 self.cell_width, 
								 		 self.cell_height]
				)

	def run(self) -> None:
		'''
		- continously runs the animation
		- updates the grid object with each frame of the animation
		'''
		while self.running:
			self.screen.fill((255, 255, 255))
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
