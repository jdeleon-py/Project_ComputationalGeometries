# PYGAME ENGINE CLASS

import pygame
from pygame.locals import QUIT, MOUSEBUTTONDOWN
from point import Point

class Game:
	'''
	DESCRIPTION:
		- ability to click to add more sites (points),
			the voronoi creation updates automatically

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
		self.points = []
		self.running = True

	def run(self) -> None:
		while self.running:
			self.screen.fill((0, 0, 0))
			'''draw points'''
			for point in self.points:
				pygame.draw.circle(surface = self.screen, 
								   color = (255, 255, 255), 
								   center = tuple([point.x, point.y]), 
								   radius = 3
				)
			for event in pygame.event.get():
				if event.type == QUIT: self.running = False
				elif event.type == MOUSEBUTTONDOWN:
					'''create a point and add to list of points'''
					pos = pygame.mouse.get_pos()
					self.points.append(Point(x = pos[0], y = pos[1]))
			pygame.display.flip()
			self.clock.tick(30)


if __name__ == "__main__":
	generator = Game()
	generator.run()
