# VORONOI CONSTRUCTION CLASS

from PIL import Image
from point import Point
from sector import Sector
from quadtree import QuadTree

class Voronoi(QuadTree):
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
	def __init__(self, width: int, height: int) -> None:
		self.width = width
		self.height = height
		self.image = Image.new('RGB', (self.width, self.height))
		self.sector_init = Sector(center = (self.width // 2, self.height // 2), radius = self.width // 2)
		QuadTree.__init__(self, boundary = self.sector_init)

	def func(self) -> None:
		'''if sector radius == 1, then color each corner pixel with the color of it's closest site'''
		if self.boundary.radius == 1:
			self.draw(point = self.boundary.nw_corner.closest_point)
			self.draw(point = self.boundary.ne_corner.closest_point)
			self.draw(point = self.boundary.sw_corner.closest_point)
			self.draw(point = self.boundary.se_corner.closest_point)
		# if all boundary corners share the same closest point, then color the sector with the site's color
		elif self.boundary.corner_scan(points = self.points): pass
		# else, subdivide and check again
		else:
			self.subdivide()
			self.northwest.func()
			self.northeast.func()
			self.southwest.func()
			self.southeast.func()


if __name__ == "__main__":
	import random
	vor = Voronoi(width = 512, height = 512)
	vor.points = [Point(x = random.randint(0, 512), y = random.randint(0, 512))]
	vor.func()