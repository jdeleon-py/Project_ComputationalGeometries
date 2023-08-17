# PIXEL (BASE) CLASS

import numpy as np

class Pixel:
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
		self.x = x
		self.y = y
		self.coordinates = tuple([self.x, self.y])

	def __str__(self) -> str:
		return "Coordinates: {}".format(self.coordinates)

	@staticmethod
	def distance(corner: object, point: object) -> float:
		return np.linalg.norm(np.array(corner.coordinates) - np.array(point.coordinates))


if __name__ == "__main__":
	p = Pixel(x = 233, y = 455)
	c = Pixel(x = 122, y = 23)
	print("Distance: {}".format(Pixel.distance(c, p)))