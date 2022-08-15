# POINT SITE CLASS

import random

class Point:
	'''
	DESCRIPTION:
		- this class will define the site,
			which is the central node in each voronoi shape.
		- sites will have a location and a color, the color defining
			what color the rest of the shape will look like

	METHODS:
		-

	ATTRIBUTES:
		- location coordinates (x, y)
		- color coordinates (R, G, B)
	'''
	def __init__(self, x: int, y: int):
		self.x = x
		self.y = y
		self.coordinates = tuple([self.x, self.y])
		self.color = tuple(self.define_color())

	def define_color(self) -> list:
		R = random.randint(0, 255)
		G = random.randint(0, 255)
		B = random.randint(0, 255)
		return [R, G, B]



if __name__ == "__main__":
	pass