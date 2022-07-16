import pygame
from pygame.locals import QUIT, MOUSEBUTTONDOWN
from PIL import Image
import random
import glob

class Automata:
	'''
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
		grid_copy = [[0 for _ in range(0, Automata.DIM)] for _ in range(0, Automata.DIM)]
		for row in range(1, Automata.DIM - 1):
			for column in range(1, Automata.DIM - 1):
				alive = self.check_neighbors(row, column, border = True)
				if (self.grid[row][column] == 1) and (alive < 2): grid_copy[row][column] = 0
				elif (alive in [2, 3]) and self.grid[row][column] == 1: grid_copy[row][column] = 1
				elif alive > 3 and self.grid[row][column] == 1: grid_copy[row][column] = 0
				elif alive == 3 and self.grid[row][column] == 0: grid_copy[row][column] = 1
		self.grid = grid_copy

	def run(self) -> None:
		while self.running:
			if self.generation > Automata.MAX_FRAMES: self.running = False
			self.screen.fill(Automata.WHITE)
			for event in pygame.event.get():
				if event.type == QUIT: self.running = False
				elif event.type == MOUSEBUTTONDOWN: self.__init__(save_frame = False)
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
