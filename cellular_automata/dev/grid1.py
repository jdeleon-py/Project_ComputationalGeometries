import pygame
from pygame.locals import QUIT, MOUSEBUTTONDOWN

class Grid1:
	'''
	ADAPTED FROM: http://programarcadegames.com/index.php?chapter=array_backed_grids&lang=en
	'''
	BLACK = (0, 0, 0)
	WHITE = (255, 255, 255)

	# This sets the WIDTH and HEIGHT of each grid location
	WIDTH = 29
	HEIGHT = 29

	# This sets the margin between each cell
	MARGIN = 1

	def __init__(self):
		pygame.init()
		pygame.display.set_caption("Array Backed Grid")
		self.screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
		self.clock = pygame.time.Clock()
		self.grid = self.define_grid()
		self.running = True
    
	def __str__(self):
		return "Mouse Coordinates: {0}; Grid Coordinates: ".format(row, column)

	def define_grid(self):
		grid = []
		for row in range(0, 10):
			grid.append([])
			for column in range(0, 10):
				grid[row].append(0)
		return grid

	def draw_grid(self):
		for row in range(0, 10):
			for column in range(0, 10):
				color = Grid1.BLACK
				if self.grid[row][column] == 1: color = Grid1.WHITE
				pygame.draw.rect(surface = self.screen,
								 color = color, 
								 rect = [(Grid1.MARGIN + Grid1.WIDTH) * column + Grid1.MARGIN, 
										 (Grid1.MARGIN + Grid1.HEIGHT) * row + Grid1.MARGIN, 
										 Grid1.WIDTH, 
										 Grid1.HEIGHT]
				)

	def cell_state(self):
		# Change the x/y screen coordinates to grid coordinates
		pos = pygame.mouse.get_pos()
		column = pos[0] // (Grid1.WIDTH + Grid1.MARGIN)
		row = pos[1] // (Grid1.HEIGHT + Grid1.MARGIN)
		if self.grid[row][column] == 0: self.grid[row][column] = 1
		else: self.grid[row][column] = 0
		print("Mouse Coordinates: {0}; Grid Coordinates: ({1},{2})".format(pos, row, column))

	def run(self):
		while self.running:
			self.screen.fill(Grid1.WHITE)
			for event in pygame.event.get():
				if event.type == QUIT: self.running = False
				elif event.type == MOUSEBUTTONDOWN: self.cell_state()

			# Draw the grid
			self.draw_grid()

			pygame.display.flip()
			self.clock.tick(60)

if __name__ == "__main__":
	WINDOW_WIDTH = 300
	WINDOW_HEIGHT = 300

	game = Grid1()
	game.run()
	pygame.quit()
