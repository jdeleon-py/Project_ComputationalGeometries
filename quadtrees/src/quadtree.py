# QUADTREE RECURSIVE CLASS

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
	NODE_CAPACITY = 4

	def __init__(self, boundary: object) -> None:
		self.boundary = boundary
		self.points = []
		self.divided = False

    
	def __str__(self) -> str:
		return "{}".format()


	def insert(self, point: object) -> bool:
		'''
		'''
		if not self.boundary.contains_point(point): return False
		if len(self.points) < QuadTree.NODE_CAPACITY:
			self.points.append(point)
			return True
		elif not self.divided: self.subdivide()
		if self.northwest.boundary.contains_point(point):   return self.northwest.insert(point)
		elif self.northeast.boundary.contains_point(point): return self.northeast.insert(point)
		elif self.southwest.boundary.contains_point(point): return self.southwest.insert(point)
		elif self.southeast.boundary.contains_point(point): return self.southeast.insert(point)


	def subdivide(self) -> None:
		'''
		'''
		centerx = self.boundary.center[0]
		centery = self.boundary.center[1]
		rad = self.boundary.radius
		if rad == 1: return None

		nw = tuple([centerx - (rad // 2), centery - (rad // 2)])
		ne = tuple([centerx + (rad // 2), centery - (rad // 2)])
		sw = tuple([centerx - (rad // 2), centery + (rad // 2)])
		se = tuple([centerx + (rad // 2), centery + (rad // 2)])

		self.northwest = QuadTree(boundary = Sector(center = nw, radius = rad // 2))
		self.northeast = QuadTree(boundary = Sector(center = ne, radius = rad // 2))
		self.southwest = QuadTree(boundary = Sector(center = sw, radius = rad // 2))
		self.southeast = QuadTree(boundary = Sector(center = se, radius = rad // 2))
		self.divided = True


	def draw(self, tool: object, surface: object) -> None:
		'''
		'''
		centerx = self.boundary.center[0]
		centery = self.boundary.center[1]
		radius = self.boundary.radius
		for point in self.points:
			tool.circle(surface = surface,
						color = (255, 255, 255), 
						center = (point.x, point.y), 
						radius = 2
			)
		if self.divided == True:
			''' vertical line '''
			tool.line(surface = surface,
					  color = (255, 255, 255),
					  start_pos = (centerx, centery - radius),
					  end_pos = (centerx, centery + radius),
					  width = 2
			)
			''' horizontal line '''
			tool.line(surface = surface,
					  color = (255, 255, 255),
					  start_pos = (centerx - radius, centery),
					  end_pos = (centerx + radius, centery),
					  width = 2
			)
			self.northwest.draw(tool = tool, surface = surface)
			self.northeast.draw(tool = tool, surface = surface)
			self.southwest.draw(tool = tool, surface = surface)
			self.southeast.draw(tool = tool, surface = surface)


	def query_range(self, range: object): pass


if __name__ == "__main__":
	pass
