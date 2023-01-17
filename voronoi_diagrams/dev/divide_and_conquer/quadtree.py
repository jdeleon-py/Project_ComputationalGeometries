# QUADTREE (RECURSIVE) CLASS

from sector import Sector

class QuadTree:
	'''
	DESCRIPTION:
		-

	METHODS:
		-

	ATTRIBUTES:
		-
	'''
	def __init__(self, boundary: object) -> None:
		self.boundary = boundary
		self.points = []
		self.divided = False

	def __str__(self) -> str:
		return "{}".format()

	def subdivide(self) -> None:
		'''
		'''
		centerx = self.boundary.center[0]
		centery = self.boundary.center[1]
		rad = self.boundary.radius

		nw = tuple([centerx - (rad // 2), centery - (rad // 2)])
		ne = tuple([centerx + (rad // 2), centery - (rad // 2)])
		sw = tuple([centerx - (rad // 2), centery + (rad // 2)])
		se = tuple([centerx + (rad // 2), centery + (rad // 2)])

		self.northwest = QuadTree(boundary = Sector(center = nw, radius = rad // 2))
		self.northeast = QuadTree(boundary = Sector(center = ne, radius = rad // 2))
		self.southwest = QuadTree(boundary = Sector(center = sw, radius = rad // 2))
		self.southeast = QuadTree(boundary = Sector(center = se, radius = rad // 2))
		self.divided = True

	def draw(self, img: object, point: object) -> None:
		img.putpixel(point.coordinates, point.color)


if __name__ == "__main__":
	pass
