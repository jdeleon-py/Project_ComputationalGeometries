# PYGAME VISUALIZATION CLASS

import random
import pygame
from pygame.locals import QUIT, MOUSEBUTTONDOWN
from point import Point
from sector import Sector
from quadtree import QuadTree

class Game:
	'''
	DESCRIPTION:
		-

	METHODS:
		-

	ATTRIBUTES:
		-
	'''
	def __init__(self) -> None:
		pygame.init()
		pygame.display.set_caption("Voronoi Diagram Generator")
		self.screen = pygame.display.set_mode((512, 512))
		self.clock = pygame.time.Clock()
		self.quadtree = QuadTree(boundary = Sector((256, 256), 256))
		self.running = True

	def run(self, mode = 'INTERACTIVE') -> None:
		'''
		'''
		while self.running:
			self.screen.fill((0, 0, 0))
			self.quadtree.draw(tool = pygame.draw, surface = self.screen)
			for event in pygame.event.get():
				if event.type == QUIT: self.running = False
				elif event.type == MOUSEBUTTONDOWN:
					if mode == 'INTERACTIVE':
						pos = pygame.mouse.get_pos()
						self.quadtree.insert(Point(x = pos[0], y = pos[1]))
					elif mode == 'RANDOM':
						points = [Point(random.randint(0, 512), random.randint(0, 512)) for _ in range(0, 500)]
						for p in points: self.quadtree.insert(p)

			pygame.display.flip()
			self.clock.tick(30)


if __name__ == "__main__":
	game = Game()
	game.run()
	pygame.quit()
