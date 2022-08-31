# PYGAME VISUALIZATION CLASS

import pygame
from pygame.locals import QUIT, MOUSEBUTTONDOWN
from point import Point

class Game:
	'''
	'''
	def __init__(self) -> None:
		pygame.init()
		pygame.display.set_caption("QuadTree Generator")
		self.screen = pygame.display.set_mode((512, 512))
		self.clock = pygame.time.Clock()
		self.points = []
		self.running = True

	def run(self) -> None:
		while self.running:
			self.screen.fill((0, 0, 0))
			for point in self.points:
				point.draw_point(tool = pygame.draw, surface = self.screen)
			for event in pygame.event.get():
				if event.type == QUIT: self.running = False
				elif event.type == MOUSEBUTTONDOWN:
					pos = pygame.mouse.get_pos()
					self.points.append(Point(x = pos[0], y = pos[1]))
			pygame.display.flip()
			self.clock.tick(30)


if __name__ == "__main__":
	game = Game()
	game.run()
	pygame.quit()