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
	def __init__(self, boundary: object, image: object, points: [object]) -> None:
		self.boundary = boundary
		self.points = points
		self.image = image
		self.divided = False

	def __str__(self) -> str:
		return "{}".format()

	def generate(self) -> None:
		self.boundary.corner_scan(points = self.points)
		'''if sector radius == 1, then color each corner pixel with the color of it's closest site'''
		if self.boundary.radius == 1:
			self.image.putpixel(self.boundary.nw_corner.coordinates, self.boundary.nw_corner.closest_point.color)
			self.image.putpixel(self.boundary.ne_corner.coordinates, self.boundary.ne_corner.closest_point.color)
			self.image.putpixel(self.boundary.sw_corner.coordinates, self.boundary.sw_corner.closest_point.color)
			self.image.putpixel(self.boundary.se_corner.coordinates, self.boundary.se_corner.closest_point.color)

		# if all boundary corners share the same closest point, then color the sector with the site's color
		elif self.boundary.corner_check():
			for x in range(self.boundary.nw_corner.x, self.boundary.ne_corner.x + 1):
				for y in range(self.boundary.nw_corner.y, self.boundary.sw_corner.y + 1):
					self.image.putpixel((x, y), self.boundary.nw_corner.closest_point.color)

		# else, subdivide and check again
		else:
			self.subdivide()
			self.northwest.generate()
			self.northeast.generate()
			self.southwest.generate()
			self.southeast.generate()

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

		self.northwest = QuadTree(boundary = Sector(center = nw, radius = rad // 2), image = self.image, points = self.points)
		self.northeast = QuadTree(boundary = Sector(center = ne, radius = rad // 2), image = self.image, points = self.points)
		self.southwest = QuadTree(boundary = Sector(center = sw, radius = rad // 2), image = self.image, points = self.points)
		self.southeast = QuadTree(boundary = Sector(center = se, radius = rad // 2), image = self.image, points = self.points)
		self.divided = True


if __name__ == "__main__":
	pass
