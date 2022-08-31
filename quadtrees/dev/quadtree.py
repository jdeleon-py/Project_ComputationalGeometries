# QUADTREE RECURSIVE CLASS

from sector import Sector

class QuadTree:
	'''
	'''
	CAPACITY = 4

	def __init__(self, boundary: object) -> None:
		self.boundary = boundary
		self.points = []
		self.notheast = QuadTree(boundary = self.boundary / 2)
		self.northwest = QuadTree(boundary = self.boundary / 2)
		self.southwest = QuadTree(boundary = self.boundary / 2)
		self.southeast = QuadTree(boundary = self.boundary / 2)

	def insert(self, point: object) -> bool:
		pass

	def subdivide(self) -> None:
		pass

	def query_range(self, range: object):
		pass

if __name__ == "__main__":
	pass