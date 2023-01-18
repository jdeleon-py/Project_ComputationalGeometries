# POINT (SITE, DERIVED) CLASS

import random
from pixel import Pixel

class Point(Pixel):
	'''
	DESCRIPTION:
		- nodes that populate a canvas
		- the number of nodes is governed by its enclosing sector,
			where if there is an excess number of nodes, the sector
			will subdivide into four smaller sections

	METHODS:
		- draw function driven by pygame graphics class

	ATTRIBUTES:
		- positional coordinates (x, y)
	'''
	def __init__(self, x: int, y: int) -> None:
		Pixel.__init__(self, x, y)
		self.color = self.define_color()

	def __str__(self) -> str:
		return "{0}, Color: {1}".format(Pixel.__str__(self), self.color)

	def define_color(self) -> tuple:
		R = random.randint(0, 255)
		G = random.randint(0, 255)
		B = random.randint(0, 255)
		return tuple([R, G, B])


if __name__ == "__main__":
	point = Point(x = 233, y = 145)
	print("{}".format(point))