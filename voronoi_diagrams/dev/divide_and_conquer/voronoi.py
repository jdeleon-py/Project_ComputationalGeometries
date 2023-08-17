# VORONOI (QUADTREE) CONSTRUCTION CLASS

from PIL import Image
from sector import Sector
from quadtree import QuadTree

class Voronoi:
	'''
	DESCRIPTION:
		- uses a recursive divide and conquer algorithm to
			define the boundaries of each voronoi shape
		- cells will divide based on euclidian measurements
			to each site, defining the highest resolution of
			a cell to 1x1 pixel

	METHODS:
		-

	ATTRIBUTES:
		- 
	'''
	def __init__(self, width: int, height: int, points: [object]) -> None:
		self.width = width
		self.height = height
		self.points = points
		self.image = Image.new('RGB', (self.width, self.height))
		self.sector_init = Sector(center = (self.width // 2, self.height // 2), radius = self.width // 2)
		self.quadtree = QuadTree(boundary = self.sector_init, image = self.image, points = self.points)

	def construct(self) -> None: self.quadtree.generate()


if __name__ == "__main__":
	import random
	from point import Point

	points = [Point(x = random.randint(0, 512), y = random.randint(0, 512)) for _ in range(0, 50)]
	vor = Voronoi(width = 512, height = 512, points = points)
	vor.construct()
	vor.image.show()
