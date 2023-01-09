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
		self.color = tuple([random.randint(0, 255) for _ in range(0, 3)])

	def __str__(self) -> str:
		return "Coordinates: {0}, Color: {1}".format(self.coordinates, self.color)


if __name__ == "__main__":
	points = [Point(random.randint(0, 100), random.randint(0, 100)) for _ in range(0, 10)]
	for point in points: print(point)
