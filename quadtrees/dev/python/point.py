# POINT (SITE) CLASS

class Point:
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

	def __str__(self) -> str:
		return "Coordinates: ({0}, {1})".format(self.x, self.y)


if __name__ == "__main__":
	pass