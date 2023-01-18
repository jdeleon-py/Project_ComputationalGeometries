# CORNER (DERIVED) CLASS

from pixel import Pixel

class Corner(Pixel):
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
		self.minimum_distance = 10000
		self.closest_point = None

	def __str__(self) -> str:
		return "{0}, Closest Point: {1}".format(Pixel.__str__(self), self.closest_point)

	def __eq__(self, corner: object) -> bool:
		return True if self.closest_point == corner.closest_point else False


if __name__ == "__main__":
	corner = Corner(x = 12, y = 140)
	print("{}".format(corner))